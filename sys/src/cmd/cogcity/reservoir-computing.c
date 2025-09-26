/*
 * AtomSpace Reservoir Computing Implementation
 * Echo State Network for cognitive pattern processing in AtomSpace
 */

#include "reservoir-computing.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Utility Functions */

double** 
allocate_matrix(int rows, int cols) {
    double **matrix = mallocz(sizeof(double*) * rows, 1);
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i] = mallocz(sizeof(double) * cols, 1);
    }
    return matrix;
}

void 
free_matrix(double** matrix, int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double 
random_weight(double scale) {
    return ((double)rand() / RAND_MAX - 0.5) * 2.0 * scale;
}

double 
tanh_activation(double x) {
    return tanh(x);
}

double 
spectral_radius(double** matrix, int size) {
    /* Simplified spectral radius calculation using power iteration */
    double *x = mallocz(sizeof(double) * size, 1);
    double *y = mallocz(sizeof(double) * size, 1);
    int i, j, iter;
    double norm, lambda = 0.0;
    
    /* Initialize random vector */
    for (i = 0; i < size; i++) {
        x[i] = random_weight(1.0);
    }
    
    /* Power iteration */
    for (iter = 0; iter < 100; iter++) {
        /* y = A * x */
        for (i = 0; i < size; i++) {
            y[i] = 0.0;
            for (j = 0; j < size; j++) {
                y[i] += matrix[i][j] * x[j];
            }
        }
        
        /* Compute norm */
        norm = 0.0;
        for (i = 0; i < size; i++) {
            norm += y[i] * y[i];
        }
        norm = sqrt(norm);
        
        if (norm > 0) {
            lambda = norm;
            /* Normalize */
            for (i = 0; i < size; i++) {
                x[i] = y[i] / norm;
            }
        }
    }
    
    free(x);
    free(y);
    return lambda;
}

void 
normalize_spectral_radius(double** matrix, int size, double target_radius) {
    double current_radius = spectral_radius(matrix, size);
    if (current_radius > 0) {
        double scale = target_radius / current_radius;
        int i, j;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                matrix[i][j] *= scale;
            }
        }
    }
}

/* Echo State Network Implementation */

EchoStateNetwork* 
create_echo_state_network(ESNConfig config) {
    EchoStateNetwork *esn = mallocz(sizeof(EchoStateNetwork), 1);
    
    esn->config = config;
    
    /* Initialize weight matrices */
    esn->weights.input_weights = allocate_matrix(config.reservoir_size, config.input_size);
    esn->weights.reservoir_weights = allocate_matrix(config.reservoir_size, config.reservoir_size);
    esn->weights.output_weights = allocate_matrix(config.output_size, config.reservoir_size);
    esn->weights.input_size = config.input_size;
    esn->weights.reservoir_size = config.reservoir_size;
    esn->weights.output_size = config.output_size;
    
    /* Initialize reservoir state */
    esn->state.neurons = mallocz(sizeof(double) * config.reservoir_size, 1);
    esn->state.prev_neurons = mallocz(sizeof(double) * config.reservoir_size, 1);
    esn->state.size = config.reservoir_size;
    esn->state.leak_rate = config.leak_rate;
    
    /* Set function pointers */
    esn->initialize = esn_initialize;
    esn->train = esn_train;
    esn->predict = esn_predict;
    esn->update_reservoir = esn_update_reservoir;
    esn->integrate_atomspace = esn_integrate_atomspace;
    
    /* Initialize pattern storage */
    esn->pattern_atoms = nil;
    esn->pattern_count = 0;
    esn->atomspace = nil;
    
    print("🧠 Created Echo State Network: %dx%dx%d\n", 
          config.input_size, config.reservoir_size, config.output_size);
    
    return esn;
}

void 
esn_initialize(EchoStateNetwork* esn) {
    int i, j;
    ESNConfig *config = &esn->config;
    
    srand(time(nil));
    
    /* Initialize input weights */
    for (i = 0; i < config->reservoir_size; i++) {
        for (j = 0; j < config->input_size; j++) {
            esn->weights.input_weights[i][j] = random_weight(config->input_scaling);
        }
    }
    
    /* Initialize reservoir weights (sparse random) */
    double connectivity = 0.1; /* 10% connectivity */
    for (i = 0; i < config->reservoir_size; i++) {
        for (j = 0; j < config->reservoir_size; j++) {
            if (((double)rand() / RAND_MAX) < connectivity) {
                esn->weights.reservoir_weights[i][j] = random_weight(1.0);
            } else {
                esn->weights.reservoir_weights[i][j] = 0.0;
            }
        }
    }
    
    /* Normalize spectral radius */
    normalize_spectral_radius(esn->weights.reservoir_weights, 
                            config->reservoir_size, 
                            config->spectral_radius);
    
    /* Initialize output weights to zero (will be trained) */
    for (i = 0; i < config->output_size; i++) {
        for (j = 0; j < config->reservoir_size; j++) {
            esn->weights.output_weights[i][j] = 0.0;
        }
    }
    
    /* Initialize reservoir state */
    for (i = 0; i < config->reservoir_size; i++) {
        esn->state.neurons[i] = 0.0;
        esn->state.prev_neurons[i] = 0.0;
    }
    
    print("🔧 Initialized ESN with spectral radius: %.3f\n", config->spectral_radius);
}

void 
esn_update_reservoir(EchoStateNetwork* esn, double* input) {
    int i, j;
    ESNConfig *config = &esn->config;
    double *new_state = mallocz(sizeof(double) * config->reservoir_size, 1);
    
    /* Save previous state */
    for (i = 0; i < config->reservoir_size; i++) {
        esn->state.prev_neurons[i] = esn->state.neurons[i];
    }
    
    /* Compute new reservoir state */
    for (i = 0; i < config->reservoir_size; i++) {
        double activation = 0.0;
        
        /* Input contribution */
        for (j = 0; j < config->input_size; j++) {
            activation += esn->weights.input_weights[i][j] * input[j];
        }
        
        /* Recurrent contribution */
        for (j = 0; j < config->reservoir_size; j++) {
            activation += esn->weights.reservoir_weights[i][j] * esn->state.prev_neurons[j];
        }
        
        /* Add noise */
        activation += random_weight(config->noise_level);
        
        /* Apply activation function */
        new_state[i] = tanh_activation(activation);
        
        /* Apply leaky integration */
        esn->state.neurons[i] = (1.0 - config->leak_rate) * esn->state.prev_neurons[i] + 
                                config->leak_rate * new_state[i];
    }
    
    free(new_state);
}

double* 
esn_predict(EchoStateNetwork* esn, double* input) {
    int i, j;
    ESNConfig *config = &esn->config;
    
    /* Update reservoir with input */
    esn_update_reservoir(esn, input);
    
    /* Compute output */
    double *output = mallocz(sizeof(double) * config->output_size, 1);
    for (i = 0; i < config->output_size; i++) {
        output[i] = 0.0;
        for (j = 0; j < config->reservoir_size; j++) {
            output[i] += esn->weights.output_weights[i][j] * esn->state.neurons[j];
        }
    }
    
    return output;
}

void 
esn_train(EchoStateNetwork* esn, double** inputs, double** outputs, int samples) {
    int i, j, k;
    ESNConfig *config = &esn->config;
    
    print("🎓 Training ESN with %d samples...\n", samples);
    
    /* Collect reservoir states */
    double **states = allocate_matrix(samples, config->reservoir_size);
    
    /* Run inputs through reservoir */
    for (i = 0; i < samples; i++) {
        esn_update_reservoir(esn, inputs[i]);
        for (j = 0; j < config->reservoir_size; j++) {
            states[i][j] = esn->state.neurons[j];
        }
    }
    
    /* Solve linear regression for output weights using pseudoinverse */
    /* Simplified training: least squares solution */
    for (i = 0; i < config->output_size; i++) {
        for (j = 0; j < config->reservoir_size; j++) {
            double numerator = 0.0, denominator = 0.0;
            
            for (k = 0; k < samples; k++) {
                numerator += outputs[k][i] * states[k][j];
                denominator += states[k][j] * states[k][j];
            }
            
            if (denominator > 1e-10) {
                esn->weights.output_weights[i][j] = numerator / denominator;
            }
        }
    }
    
    free_matrix(states, samples);
    print("✅ ESN training completed\n");
}

void 
esn_integrate_atomspace(EchoStateNetwork* esn, AtomSpaceService* atomspace) {
    esn->atomspace = atomspace;
    
    /* Allocate pattern storage */
    esn->pattern_atoms = mallocz(sizeof(Atom*) * atomspace->atom_capacity, 1);
    esn->pattern_count = 0;
    
    print("🔗 Integrated ESN with AtomSpace: %s\n", atomspace->service_name);
}

void 
esn_destroy(EchoStateNetwork* esn) {
    if (!esn) return;
    
    free_matrix(esn->weights.input_weights, esn->config.reservoir_size);
    free_matrix(esn->weights.reservoir_weights, esn->config.reservoir_size);
    free_matrix(esn->weights.output_weights, esn->config.output_size);
    
    free(esn->state.neurons);
    free(esn->state.prev_neurons);
    
    if (esn->pattern_atoms) {
        free(esn->pattern_atoms);
    }
    
    free(esn);
}

/* AtomSpace Reservoir Computing Service */

AtomSpaceReservoir* 
create_atomspace_reservoir(char* service_name, ESNConfig config) {
    AtomSpaceReservoir *reservoir = mallocz(sizeof(AtomSpaceReservoir), 1);
    
    reservoir->service_name = strdup(service_name);
    reservoir->esn = create_echo_state_network(config);
    reservoir->pattern_channel = chancreate(sizeof(Atom*), 64);
    reservoir->prediction_channel = chancreate(sizeof(double*), 64);
    
    /* Set function pointers */
    reservoir->process_atom_pattern = atomspace_reservoir_process_pattern;
    reservoir->learn_from_interactions = atomspace_reservoir_learn;
    reservoir->predict_atom_behavior = atomspace_reservoir_predict;
    reservoir->adapt_to_atomspace_changes = atomspace_reservoir_adapt;
    
    /* Initialize ESN */
    reservoir->esn->initialize(reservoir->esn);
    
    print("🏛️ Created AtomSpace Reservoir: %s\n", service_name);
    return reservoir;
}

void 
atomspace_reservoir_process_pattern(AtomSpaceReservoir* reservoir, Atom* atom) {
    if (!reservoir || !atom) return;
    
    /* Convert atom to input vector */
    double *input = mallocz(sizeof(double) * reservoir->esn->config.input_size, 1);
    
    /* Encode atom properties into input vector */
    input[0] = (double)atom->type / 100.0;  /* Normalized atom type */
    input[1] = atom->outgoing_size / 10.0;  /* Normalized outgoing count */
    input[2] = atom->tv ? atom->tv->strength : 0.5;  /* Truth value strength */
    input[3] = atom->tv ? atom->tv->confidence : 0.5; /* Truth value confidence */
    input[4] = atom->av ? atom->av->sti / 100.0 : 0.0; /* Attention value */
    
    /* Fill remaining inputs with structural features */
    int i;
    for (i = 5; i < reservoir->esn->config.input_size; i++) {
        input[i] = random_weight(0.1); /* Placeholder for complex features */
    }
    
    /* Update reservoir state */
    reservoir->esn->update_reservoir(reservoir->esn, input);
    
    /* Send pattern for processing */
    if (reservoir->pattern_channel) {
        chansend(reservoir->pattern_channel, &atom);
    }
    
    free(input);
}

double* 
atomspace_reservoir_predict(AtomSpaceReservoir* reservoir, Atom* atom) {
    if (!reservoir || !atom) return nil;
    
    /* Convert atom to input vector */
    double *input = mallocz(sizeof(double) * reservoir->esn->config.input_size, 1);
    
    /* Encode atom properties */
    input[0] = (double)atom->type / 100.0;
    input[1] = atom->outgoing_size / 10.0;
    input[2] = atom->tv ? atom->tv->strength : 0.5;
    input[3] = atom->tv ? atom->tv->confidence : 0.5;
    input[4] = atom->av ? atom->av->sti / 100.0 : 0.0;
    
    int i;
    for (i = 5; i < reservoir->esn->config.input_size; i++) {
        input[i] = 0.0;
    }
    
    /* Get prediction */
    double *prediction = reservoir->esn->predict(reservoir->esn, input);
    
    free(input);
    return prediction;
}

void 
atomspace_reservoir_learn(AtomSpaceReservoir* reservoir) {
    if (!reservoir || !reservoir->atomspace) return;
    
    print("🧠 Learning from AtomSpace interactions...\n");
    
    /* Create training data from atomspace patterns */
    int sample_count = reservoir->atomspace->atom_count / 2;  /* Use half for training */
    if (sample_count < 10) sample_count = 10;
    
    double **inputs = allocate_matrix(sample_count, reservoir->esn->config.input_size);
    double **outputs = allocate_matrix(sample_count, reservoir->esn->config.output_size);
    
    /* Generate training samples from atoms */
    int i, j;
    for (i = 0; i < sample_count && i < reservoir->atomspace->atom_count; i++) {
        Atom *atom = reservoir->atomspace->atoms[i];
        if (atom) {
            /* Input features */
            inputs[i][0] = (double)atom->type / 100.0;
            inputs[i][1] = atom->outgoing_size / 10.0;
            inputs[i][2] = atom->tv ? atom->tv->strength : 0.5;
            inputs[i][3] = atom->tv ? atom->tv->confidence : 0.5;
            inputs[i][4] = atom->av ? atom->av->sti / 100.0 : 0.0;
            
            for (j = 5; j < reservoir->esn->config.input_size; j++) {
                inputs[i][j] = random_weight(0.1);
            }
            
            /* Output targets (example: predict next state) */
            outputs[i][0] = atom->tv ? atom->tv->strength : 0.5;
            outputs[i][1] = atom->av ? atom->av->sti / 100.0 + 0.1 : 0.1;
            
            for (j = 2; j < reservoir->esn->config.output_size; j++) {
                outputs[i][j] = 0.0;
            }
        }
    }
    
    /* Train the ESN */
    reservoir->esn->train(reservoir->esn, inputs, outputs, sample_count);
    
    free_matrix(inputs, sample_count);
    free_matrix(outputs, sample_count);
    
    print("✅ AtomSpace reservoir learning completed\n");
}

void 
atomspace_reservoir_adapt(AtomSpaceReservoir* reservoir) {
    if (!reservoir) return;
    
    print("🔄 Adapting reservoir to AtomSpace changes...\n");
    
    /* Re-learn from updated atomspace */
    atomspace_reservoir_learn(reservoir);
}

void 
atomspace_reservoir_destroy(AtomSpaceReservoir* reservoir) {
    if (!reservoir) return;
    
    esn_destroy(reservoir->esn);
    
    if (reservoir->pattern_channel) {
        chanclose(reservoir->pattern_channel);
    }
    if (reservoir->prediction_channel) {
        chanclose(reservoir->prediction_channel);
    }
    
    free(reservoir->service_name);
    free(reservoir);
}

/* Demo Function */

void 
demo_atomspace_reservoir_computing(AtomSpaceService* atomspace) {
    print("\n🎯 === AtomSpace Reservoir Computing Demo ===\n");
    
    /* Create ESN configuration */
    ESNConfig config = {
        .input_size = 8,
        .reservoir_size = 50,
        .output_size = 3,
        .spectral_radius = 0.9,
        .input_scaling = 0.5,
        .leak_rate = 0.3,
        .noise_level = 0.01
    };
    
    /* Create reservoir */
    AtomSpaceReservoir *reservoir = create_atomspace_reservoir("CognitiveReservoir", config);
    reservoir->atomspace = atomspace;
    reservoir->esn->integrate_atomspace(reservoir->esn, atomspace);
    
    /* Process some atoms through the reservoir */
    print("\n📊 Processing AtomSpace patterns...\n");
    int i;
    for (i = 0; i < 5 && i < atomspace->atom_count; i++) {
        Atom *atom = atomspace->atoms[i];
        if (atom) {
            print("Processing atom %d: %s (type: %d)\n", 
                  atom->atom_id, 
                  atom->name ? atom->name : "unnamed",
                  atom->type);
            
            reservoir->process_atom_pattern(reservoir, atom);
            
            /* Get prediction */
            double *prediction = reservoir->predict_atom_behavior(reservoir, atom);
            if (prediction) {
                print("  Prediction: [%.3f, %.3f, %.3f]\n", 
                      prediction[0], prediction[1], prediction[2]);
                free(prediction);
            }
        }
    }
    
    /* Train the reservoir */
    print("\n🎓 Training reservoir on AtomSpace patterns...\n");
    reservoir->learn_from_interactions(reservoir);
    
    /* Test predictions after training */
    print("\n🔮 Testing predictions after training...\n");
    for (i = 0; i < 3 && i < atomspace->atom_count; i++) {
        Atom *atom = atomspace->atoms[i];
        if (atom) {
            double *prediction = reservoir->predict_atom_behavior(reservoir, atom);
            if (prediction) {
                print("Atom %d prediction: [%.3f, %.3f, %.3f]\n", 
                      atom->atom_id, prediction[0], prediction[1], prediction[2]);
                free(prediction);
            }
        }
    }
    
    print("\n💡 Reservoir Computing Stats:\n");
    print("  Input dimensions: %d\n", config.input_size);
    print("  Reservoir size: %d neurons\n", config.reservoir_size);
    print("  Output dimensions: %d\n", config.output_size);
    print("  Spectral radius: %.3f\n", config.spectral_radius);
    print("  Processed %d atom patterns\n", atomspace->atom_count);
    
    /* Cleanup */
    atomspace_reservoir_destroy(reservoir);
    
    print("\n✅ AtomSpace Reservoir Computing demo completed!\n");
}