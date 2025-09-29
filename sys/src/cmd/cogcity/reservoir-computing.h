/*
 * AtomSpace Reservoir Computing with Echo State Network
 * Implementation of reservoir computing for cognitive pattern processing
 */

#ifndef RESERVOIR_COMPUTING_H
#define RESERVOIR_COMPUTING_H

#include "opencog-p9-impl.h"

/* Echo State Network Configuration */
typedef struct ESNConfig {
    int input_size;         /* Number of input neurons */
    int reservoir_size;     /* Number of reservoir neurons */
    int output_size;        /* Number of output neurons */
    double spectral_radius; /* Spectral radius for stability */
    double input_scaling;   /* Input connection scaling */
    double leak_rate;       /* Leaking rate for reservoir */
    double noise_level;     /* Noise level for robustness */
} ESNConfig;

/* Reservoir State */
typedef struct ReservoirState {
    double *neurons;        /* Current neuron activations */
    double *prev_neurons;   /* Previous neuron activations */
    int size;              /* Number of neurons */
    double leak_rate;      /* Leaking rate */
} ReservoirState;

/* Weight Matrices */
typedef struct WeightMatrices {
    double **input_weights;     /* Input to reservoir weights */
    double **reservoir_weights; /* Recurrent reservoir weights */
    double **output_weights;    /* Reservoir to output weights */
    int input_size;
    int reservoir_size;
    int output_size;
} WeightMatrices;

/* Echo State Network */
typedef struct EchoStateNetwork {
    ESNConfig config;
    WeightMatrices weights;
    ReservoirState state;
    
    /* Training data */
    double **training_inputs;
    double **training_outputs;
    int training_samples;
    
    /* AtomSpace integration */
    AtomSpaceService *atomspace;
    Atom **pattern_atoms;
    int pattern_count;
    
    /* Function pointers */
    void (*initialize)(struct EchoStateNetwork*);
    void (*train)(struct EchoStateNetwork*, double**, double**, int);
    double* (*predict)(struct EchoStateNetwork*, double*);
    void (*update_reservoir)(struct EchoStateNetwork*, double*);
    void (*integrate_atomspace)(struct EchoStateNetwork*, AtomSpaceService*);
} EchoStateNetwork;

/* AtomSpace Reservoir Computing Service */
typedef struct AtomSpaceReservoir {
    char *service_name;
    EchoStateNetwork *esn;
    AtomSpaceService *atomspace;
    Channel *pattern_channel;
    Channel *prediction_channel;
    
    /* Cognitive pattern processing */
    void (*process_atom_pattern)(struct AtomSpaceReservoir*, Atom*);
    void (*learn_from_interactions)(struct AtomSpaceReservoir*);
    double* (*predict_atom_behavior)(struct AtomSpaceReservoir*, Atom*);
    void (*adapt_to_atomspace_changes)(struct AtomSpaceReservoir*);
} AtomSpaceReservoir;

/* Function Prototypes */
EchoStateNetwork* create_echo_state_network(ESNConfig config);
void esn_initialize(EchoStateNetwork* esn);
void esn_train(EchoStateNetwork* esn, double** inputs, double** outputs, int samples);
double* esn_predict(EchoStateNetwork* esn, double* input);
void esn_update_reservoir(EchoStateNetwork* esn, double* input);
void esn_integrate_atomspace(EchoStateNetwork* esn, AtomSpaceService* atomspace);
void esn_destroy(EchoStateNetwork* esn);

AtomSpaceReservoir* create_atomspace_reservoir(char* service_name, ESNConfig config);
void atomspace_reservoir_process_pattern(AtomSpaceReservoir* reservoir, Atom* atom);
void atomspace_reservoir_learn(AtomSpaceReservoir* reservoir);
double* atomspace_reservoir_predict(AtomSpaceReservoir* reservoir, Atom* atom);
void atomspace_reservoir_adapt(AtomSpaceReservoir* reservoir);
void atomspace_reservoir_destroy(AtomSpaceReservoir* reservoir);

/* Utility functions */
double** allocate_matrix(int rows, int cols);
void free_matrix(double** matrix, int rows);
double random_weight(double scale);
double tanh_activation(double x);
double spectral_radius(double** matrix, int size);
void normalize_spectral_radius(double** matrix, int size, double target_radius);

/* Demo function */
void demo_atomspace_reservoir_computing(AtomSpaceService* atomspace);

#endif /* RESERVOIR_COMPUTING_H */