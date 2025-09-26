/*
 * AtomSpace Service Implementation
 * OpenCog AtomSpace as a Plan 9 filesystem service
 */

#include "opencog-p9-impl.h"

/*
 * AtomSpace Service Implementation
 * Presents atoms as files in a hierarchical filesystem
 */

AtomSpaceService*
create_atomspace_service(char* service_name) {
    AtomSpaceService *service = mallocz(sizeof(AtomSpaceService), 1);
    
    service->service_name = strdup(service_name);
    service->request_channel = chancreate(sizeof(void*), 64);
    service->response_channel = chancreate(sizeof(void*), 64);
    
    /* Initialize atom storage */
    service->atom_capacity = 10000;  /* Initial capacity */
    service->atoms = mallocz(sizeof(Atom*) * service->atom_capacity, 1);
    service->atom_count = 0;
    
    /* Initialize indices */
    service->type_index = nil;      /* TODO: Implement hash table */
    service->name_index = nil;      /* TODO: Implement hash table */
    service->incoming_index = nil;  /* TODO: Implement hash table */
    
    /* Set up service operations */
    service->add_atom = atomspace_add_atom;
    service->remove_atom = atomspace_remove_atom;
    service->get_atom = atomspace_get_atom;
    service->get_atoms_by_type = atomspace_get_atoms_by_type;
    service->update_truth_value = atomspace_update_truth_value;
    service->update_attention_value = atomspace_update_attention_value;
    
    /* Filesystem interface */
    service->serve_filesystem = serve_atomspace_filesystem;
    service->atom_to_path = atomspace_atom_to_path;
    service->path_to_atom = atomspace_path_to_atom;
    
    print("🧠 Created AtomSpace service: %s\n", service_name);
    print("  Capacity: %d atoms\n", service->atom_capacity);
    print("  Filesystem interface: enabled\n");
    
    return service;
}

Atom*
atomspace_add_atom(AtomSpaceService* service, enum AtomType type, char* name, 
                   Atom** outgoing, int outgoing_size) {
    if (!service) return nil;
    
    /* Check capacity */
    if (service->atom_count >= service->atom_capacity) {
        print("⚠️  AtomSpace at capacity, expanding...\n");
        service->atom_capacity *= 2;
        service->atoms = realloc(service->atoms, 
                                sizeof(Atom*) * service->atom_capacity);
    }
    
    /* Create new atom */
    Atom *atom = create_atom(type, name, outgoing, outgoing_size);
    if (!atom) return nil;
    
    /* Add to storage */
    atom->atom_id = service->atom_count;
    service->atoms[service->atom_count] = atom;
    service->atom_count++;
    
    /* Update incoming links for outgoing atoms */
    if (outgoing && outgoing_size > 0) {
        int i;
        for (i = 0; i < outgoing_size; i++) {
            if (outgoing[i]) {
                atomspace_add_incoming_link(outgoing[i], atom);
            }
        }
    }
    
    print("➕ Added atom %d: %s (%s)\n", 
          atom->atom_id, 
          name ? name : "unnamed", 
          atom_type_to_string(type));
    
    return atom;
}

int
atomspace_remove_atom(AtomSpaceService* service, Atom* atom) {
    if (!service || !atom) return -1;
    
    /* Remove from incoming links of outgoing atoms */
    if (atom->outgoing && atom->outgoing_size > 0) {
        int i;
        for (i = 0; i < atom->outgoing_size; i++) {
            if (atom->outgoing[i]) {
                atomspace_remove_incoming_link(atom->outgoing[i], atom);
            }
        }
    }
    
    /* Remove from storage */
    if (atom->atom_id >= 0 && atom->atom_id < service->atom_count) {
        service->atoms[atom->atom_id] = nil;
    }
    
    print("➖ Removed atom %d\n", atom->atom_id);
    
    destroy_atom(atom);
    return 0;
}

Atom*
atomspace_get_atom(AtomSpaceService* service, int atom_id) {
    if (!service || atom_id < 0 || atom_id >= service->atom_count) {
        return nil;
    }
    
    return service->atoms[atom_id];
}

Atom**
atomspace_get_atoms_by_type(AtomSpaceService* service, enum AtomType type, int* count) {
    if (!service || !count) return nil;
    
    /* Simple linear search - TODO: Use type index for efficiency */
    Atom **results = mallocz(sizeof(Atom*) * service->atom_count, 1);
    int result_count = 0;
    
    int i;
    for (i = 0; i < service->atom_count; i++) {
        if (service->atoms[i] && service->atoms[i]->type == type) {
            results[result_count] = service->atoms[i];
            result_count++;
        }
    }
    
    *count = result_count;
    return results;
}

int
atomspace_update_truth_value(AtomSpaceService* service, Atom* atom, TruthValue* tv) {
    if (!service || !atom || !tv) return -1;
    
    if (atom->tv) {
        free(atom->tv);
    }
    
    atom->tv = mallocz(sizeof(TruthValue), 1);
    *atom->tv = *tv;  /* Copy truth value */
    
    /* Notify through update channel */
    if (atom->update_channel) {
        sendp(atom->update_channel, "truth_value_updated");
    }
    
    print("📊 Updated truth value for atom %d: strength=%.3f, confidence=%.3f\n",
          atom->atom_id, tv->strength, tv->confidence);
    
    return 0;
}

int
atomspace_update_attention_value(AtomSpaceService* service, Atom* atom, AttentionValue* av) {
    if (!service || !atom || !av) return -1;
    
    if (atom->av) {
        free(atom->av);
    }
    
    atom->av = mallocz(sizeof(AttentionValue), 1);
    *atom->av = *av;  /* Copy attention value */
    
    /* Notify through update channel */
    if (atom->update_channel) {
        sendp(atom->update_channel, "attention_value_updated");
    }
    
    print("⚡ Updated attention value for atom %d: STI=%.3f, LTI=%.3f\n",
          atom->atom_id, av->sti, av->lti);
    
    return 0;
}

/*
 * Filesystem Interface Implementation
 * Presents AtomSpace as Plan 9 filesystem hierarchy
 */

void
serve_atomspace_filesystem(AtomSpaceService* service) {
    if (!service) return;
    
    print("📁 Starting AtomSpace filesystem service: %s\n", service->service_name);
    print("  Namespace: /proc/cognition/atomspace/\n");
    print("  Protocol: 9P extended for cognitive operations\n");
    
    /* TODO: Implement full 9P file server */
    /* This would integrate with Plan 9's file server infrastructure */
    /* For now, we simulate the filesystem interface */
    
    atomspace_simulate_filesystem_operations(service);
}

void
atomspace_simulate_filesystem_operations(AtomSpaceService* service) {
    print("\n📂 AtomSpace Filesystem Operations Demo:\n");
    
    /* Simulate listing concepts */
    print("$ ls /proc/cognition/atomspace/concepts/\n");
    Atom **concepts;
    int concept_count;
    concepts = service->get_atoms_by_type(service, CONCEPT_NODE, &concept_count);
    
    int i;
    for (i = 0; i < concept_count; i++) {
        if (concepts[i] && concepts[i]->name) {
            print("  %s/\n", concepts[i]->name);
        }
    }
    
    if (concept_count == 0) {
        print("  (no concepts yet - create some with: mkdir /proc/cognition/atomspace/concepts/cat/)\n");
    }
    
    free(concepts);
    
    /* Simulate reading atom properties */
    if (concept_count > 0) {
        Atom *sample_atom = service->atoms[0];
        if (sample_atom && sample_atom->name) {
            print("\n$ cat /proc/cognition/atomspace/concepts/%s/strength\n", sample_atom->name);
            if (sample_atom->tv) {
                print("%.6f\n", sample_atom->tv->strength);
            } else {
                print("0.500000\n");  /* Default value */
            }
            
            print("\n$ cat /proc/cognition/atomspace/concepts/%s/type\n", sample_atom->name);
            print("%s\n", atom_type_to_string(sample_atom->type));
        }
    }
    
    /* Simulate query interface */
    print("\n$ echo '(InheritanceLink ConceptNode:animal ConceptNode:cat)' > /proc/cognition/atomspace/query\n");
    print("$ cat /proc/cognition/atomspace/results\n");
    print("  Query processed - no matching patterns found\n");
    print("  (Results would appear here for actual queries)\n");
}

char*
atomspace_atom_to_path(AtomSpaceService* service, Atom* atom) {
    if (!service || !atom) return nil;
    
    char *path = mallocz(256, 1);
    
    switch (atom->type) {
    case CONCEPT_NODE:
        if (atom->name) {
            snprint(path, 256, "/proc/cognition/atomspace/concepts/%s", atom->name);
        } else {
            snprint(path, 256, "/proc/cognition/atomspace/concepts/atom_%d", atom->atom_id);
        }
        break;
        
    case PREDICATE_NODE:
        if (atom->name) {
            snprint(path, 256, "/proc/cognition/atomspace/predicates/%s", atom->name);
        } else {
            snprint(path, 256, "/proc/cognition/atomspace/predicates/atom_%d", atom->atom_id);
        }
        break;
        
    case INHERITANCE_LINK:
        snprint(path, 256, "/proc/cognition/atomspace/links/inheritance/link_%d", atom->atom_id);
        break;
        
    case SIMILARITY_LINK:
        snprint(path, 256, "/proc/cognition/atomspace/links/similarity/link_%d", atom->atom_id);
        break;
        
    default:
        snprint(path, 256, "/proc/cognition/atomspace/atoms/atom_%d", atom->atom_id);
        break;
    }
    
    return path;
}

Atom*
atomspace_path_to_atom(AtomSpaceService* service, char* path) {
    if (!service || !path) return nil;
    
    /* Simple path parsing - TODO: Implement full path resolution */
    if (strstr(path, "/concepts/")) {
        /* Extract concept name from path */
        char *name_start = strstr(path, "/concepts/") + 10;
        char *name_end = strchr(name_start, '/');
        
        if (name_end) *name_end = '\0';
        
        /* Search for atom by name */
        int i;
        for (i = 0; i < service->atom_count; i++) {
            if (service->atoms[i] && 
                service->atoms[i]->type == CONCEPT_NODE &&
                service->atoms[i]->name &&
                strcmp(service->atoms[i]->name, name_start) == 0) {
                return service->atoms[i];
            }
        }
    }
    
    return nil;
}

/*
 * Helper Functions
 */

int
atomspace_add_incoming_link(Atom* target, Atom* link) {
    if (!target || !link) return -1;
    
    /* Expand incoming array if needed */
    if (target->incoming_size == 0) {
        target->incoming = mallocz(sizeof(Atom*) * 4, 1);
        target->incoming_size = 0;
    }
    
    /* Add link to incoming array */
    /* TODO: Check for duplicates and resize array as needed */
    target->incoming[target->incoming_size] = link;
    target->incoming_size++;
    
    return 0;
}

int
atomspace_remove_incoming_link(Atom* target, Atom* link) {
    if (!target || !link || !target->incoming) return -1;
    
    /* Find and remove link from incoming array */
    int i;
    for (i = 0; i < target->incoming_size; i++) {
        if (target->incoming[i] == link) {
            /* Shift remaining elements */
            int j;
            for (j = i; j < target->incoming_size - 1; j++) {
                target->incoming[j] = target->incoming[j + 1];
            }
            target->incoming_size--;
            return 0;
        }
    }
    
    return -1;  /* Link not found */
}

/*
 * Demo Functions for Testing
 */

void
demo_atomspace_service(void) {
    print("\n🌟 ATOMSPACE SERVICE DEMO 🌟\n");
    print("═══════════════════════════════\n");
    
    /* Create AtomSpace service */
    AtomSpaceService *atomspace = create_atomspace_service("demo_atomspace");
    
    /* Create some sample atoms */
    Atom *cat = atomspace->add_atom(atomspace, CONCEPT_NODE, "cat", nil, 0);
    Atom *animal = atomspace->add_atom(atomspace, CONCEPT_NODE, "animal", nil, 0);
    Atom *mammal = atomspace->add_atom(atomspace, CONCEPT_NODE, "mammal", nil, 0);
    
    /* Create links between concepts */
    Atom *outgoing1[] = {cat, animal};
    Atom *inheritance1 = atomspace->add_atom(atomspace, INHERITANCE_LINK, nil, outgoing1, 2);
    
    Atom *outgoing2[] = {cat, mammal};
    Atom *inheritance2 = atomspace->add_atom(atomspace, INHERITANCE_LINK, nil, outgoing2, 2);
    
    /* Update truth values */
    TruthValue tv1 = {0.9, 0.8, 10.0};
    atomspace->update_truth_value(atomspace, cat, &tv1);
    
    TruthValue tv2 = {0.95, 0.9, 15.0};
    atomspace->update_truth_value(atomspace, inheritance1, &tv2);
    
    /* Update attention values */
    AttentionValue av1 = {100.0, 50.0, 10.0, 5};
    atomspace->update_attention_value(atomspace, cat, &av1);
    
    /* Demonstrate filesystem interface */
    atomspace->serve_filesystem(atomspace);
    
    /* Show atom paths */
    print("\n📍 Atom Filesystem Paths:\n");
    char *cat_path = atomspace->atom_to_path(atomspace, cat);
    char *animal_path = atomspace->atom_to_path(atomspace, animal);
    char *link_path = atomspace->atom_to_path(atomspace, inheritance1);
    
    print("  Cat concept: %s\n", cat_path);
    print("  Animal concept: %s\n", animal_path);
    print("  Inheritance link: %s\n", link_path);
    
    free(cat_path);
    free(animal_path);
    free(link_path);
    
    /* Query by type */
    print("\n🔍 Querying atoms by type:\n");
    int concept_count;
    Atom **concepts = atomspace->get_atoms_by_type(atomspace, CONCEPT_NODE, &concept_count);
    print("  Found %d ConceptNodes:\n", concept_count);
    
    int i;
    for (i = 0; i < concept_count; i++) {
        if (concepts[i] && concepts[i]->name) {
            print("    - %s (ID: %d)\n", concepts[i]->name, concepts[i]->atom_id);
        }
    }
    
    free(concepts);
    
    print("\n✅ AtomSpace service demo complete!\n");
}