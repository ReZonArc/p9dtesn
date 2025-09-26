/*
 * Atom Core Implementation
 * Basic atom creation, manipulation, and utility functions
 */

#include "opencog-p9-impl.h"

/*
 * Core Atom Management Functions
 */

Atom*
create_atom(enum AtomType type, char* name, Atom** outgoing, int outgoing_size) {
    Atom *atom = mallocz(sizeof(Atom), 1);
    
    atom->atom_id = -1;  /* Will be set by AtomSpace */
    atom->type = type;
    
    /* Set name for nodes */
    if (name) {
        atom->name = strdup(name);
    } else {
        atom->name = nil;
    }
    
    /* Set outgoing links */
    if (outgoing && outgoing_size > 0) {
        atom->outgoing = mallocz(sizeof(Atom*) * outgoing_size, 1);
        atom->outgoing_size = outgoing_size;
        
        int i;
        for (i = 0; i < outgoing_size; i++) {
            atom->outgoing[i] = outgoing[i];
        }
    } else {
        atom->outgoing = nil;
        atom->outgoing_size = 0;
    }
    
    /* Initialize incoming links (empty initially) */
    atom->incoming = nil;
    atom->incoming_size = 0;
    
    /* Initialize truth and attention values */
    atom->tv = nil;
    atom->av = nil;
    
    /* Create update notification channel */
    atom->update_channel = chancreate(sizeof(char*), 8);
    
    /* Initialize user data */
    atom->user_data = nil;
    
    return atom;
}

int
destroy_atom(Atom* atom) {
    if (!atom) return -1;
    
    /* Free name */
    if (atom->name) {
        free(atom->name);
    }
    
    /* Free outgoing array (but not the atoms themselves) */
    if (atom->outgoing) {
        free(atom->outgoing);
    }
    
    /* Free incoming array (but not the atoms themselves) */
    if (atom->incoming) {
        free(atom->incoming);
    }
    
    /* Free truth value */
    if (atom->tv) {
        free(atom->tv);
    }
    
    /* Free attention value */
    if (atom->av) {
        free(atom->av);
    }
    
    /* Close update channel */
    if (atom->update_channel) {
        chanfree(atom->update_channel);
    }
    
    /* Free user data if needed */
    if (atom->user_data) {
        free(atom->user_data);
    }
    
    /* Free the atom itself */
    free(atom);
    
    return 0;
}

TruthValue*
create_truth_value(double strength, double confidence, double count) {
    TruthValue *tv = mallocz(sizeof(TruthValue), 1);
    
    /* Clamp values to valid ranges */
    tv->strength = (strength < 0.0) ? 0.0 : (strength > 1.0) ? 1.0 : strength;
    tv->confidence = (confidence < 0.0) ? 0.0 : (confidence > 1.0) ? 1.0 : confidence;
    tv->count = (count < 0.0) ? 0.0 : count;
    
    return tv;
}

AttentionValue*
create_attention_value(double sti, double lti, double vlti) {
    AttentionValue *av = mallocz(sizeof(AttentionValue), 1);
    
    av->sti = sti;      /* Short-term importance */
    av->lti = lti;      /* Long-term importance */
    av->vlti = vlti;    /* Very long-term importance */
    av->recent_usage = 0;
    
    return av;
}

int
update_atom_truth_value(Atom* atom, TruthValue* tv) {
    if (!atom || !tv) return -1;
    
    if (atom->tv) {
        free(atom->tv);
    }
    
    atom->tv = mallocz(sizeof(TruthValue), 1);
    *atom->tv = *tv;  /* Copy truth value */
    
    return 0;
}

int
update_atom_attention_value(Atom* atom, AttentionValue* av) {
    if (!atom || !av) return -1;
    
    if (atom->av) {
        free(atom->av);
    }
    
    atom->av = mallocz(sizeof(AttentionValue), 1);
    *atom->av = *av;  /* Copy attention value */
    
    return 0;
}

/*
 * Atom Type Utilities
 */

char*
atom_type_to_string(enum AtomType type) {
    switch (type) {
    case ATOM_INVALID: return "INVALID";
    case ATOM_NODE: return "NODE";
    case ATOM_LINK: return "LINK";
    
    /* Node Types */
    case CONCEPT_NODE: return "ConceptNode";
    case PREDICATE_NODE: return "PredicateNode";
    case SCHEMA_NODE: return "SchemaNode";
    case GROUNDED_SCHEMA_NODE: return "GroundedSchemaNode";
    case VARIABLE_NODE: return "VariableNode";
    case TYPED_VARIABLE_NODE: return "TypedVariableNode";
    
    /* Link Types */
    case ORDERED_LINK: return "OrderedLink";
    case UNORDERED_LINK: return "UnorderedLink";
    case INHERITANCE_LINK: return "InheritanceLink";
    case SIMILARITY_LINK: return "SimilarityLink";
    case EVALUATION_LINK: return "EvaluationLink";
    case IMPLICATION_LINK: return "ImplicationLink";
    case EQUIVALENCE_LINK: return "EquivalenceLink";
    case AND_LINK: return "AndLink";
    case OR_LINK: return "OrLink";
    case NOT_LINK: return "NotLink";
    case LIST_LINK: return "ListLink";
    case MEMBER_LINK: return "MemberLink";
    case SUBSET_LINK: return "SubsetLink";
    
    default: return "UnknownType";
    }
}

enum AtomType
string_to_atom_type(char* type_string) {
    if (!type_string) return ATOM_INVALID;
    
    /* Node Types */
    if (strcmp(type_string, "ConceptNode") == 0) return CONCEPT_NODE;
    if (strcmp(type_string, "PredicateNode") == 0) return PREDICATE_NODE;
    if (strcmp(type_string, "SchemaNode") == 0) return SCHEMA_NODE;
    if (strcmp(type_string, "GroundedSchemaNode") == 0) return GROUNDED_SCHEMA_NODE;
    if (strcmp(type_string, "VariableNode") == 0) return VARIABLE_NODE;
    if (strcmp(type_string, "TypedVariableNode") == 0) return TYPED_VARIABLE_NODE;
    
    /* Link Types */
    if (strcmp(type_string, "OrderedLink") == 0) return ORDERED_LINK;
    if (strcmp(type_string, "UnorderedLink") == 0) return UNORDERED_LINK;
    if (strcmp(type_string, "InheritanceLink") == 0) return INHERITANCE_LINK;
    if (strcmp(type_string, "SimilarityLink") == 0) return SIMILARITY_LINK;
    if (strcmp(type_string, "EvaluationLink") == 0) return EVALUATION_LINK;
    if (strcmp(type_string, "ImplicationLink") == 0) return IMPLICATION_LINK;
    if (strcmp(type_string, "EquivalenceLink") == 0) return EQUIVALENCE_LINK;
    if (strcmp(type_string, "AndLink") == 0) return AND_LINK;
    if (strcmp(type_string, "OrLink") == 0) return OR_LINK;
    if (strcmp(type_string, "NotLink") == 0) return NOT_LINK;
    if (strcmp(type_string, "ListLink") == 0) return LIST_LINK;
    if (strcmp(type_string, "MemberLink") == 0) return MEMBER_LINK;
    if (strcmp(type_string, "SubsetLink") == 0) return SUBSET_LINK;
    
    return ATOM_INVALID;
}

/*
 * Atom String Representation
 */

char*
atom_to_string(Atom* atom) {
    if (!atom) return nil;
    
    char *result = mallocz(1024, 1);  /* Generous buffer */
    
    if (atom->type >= CONCEPT_NODE && atom->type <= TYPED_VARIABLE_NODE) {
        /* Node representation */
        if (atom->name) {
            snprint(result, 1024, "(%s \"%s\")", 
                   atom_type_to_string(atom->type), atom->name);
        } else {
            snprint(result, 1024, "(%s)", atom_type_to_string(atom->type));
        }
    } else {
        /* Link representation */
        snprint(result, 1024, "(%s", atom_type_to_string(atom->type));
        
        if (atom->outgoing && atom->outgoing_size > 0) {
            int i;
            for (i = 0; i < atom->outgoing_size; i++) {
                if (atom->outgoing[i]) {
                    char *outgoing_str = atom_to_string(atom->outgoing[i]);
                    if (outgoing_str) {
                        strncat(result, " ", 1024 - strlen(result) - 1);
                        strncat(result, outgoing_str, 1024 - strlen(result) - 1);
                        free(outgoing_str);
                    }
                }
            }
        }
        
        strncat(result, ")", 1024 - strlen(result) - 1);
    }
    
    /* Add truth value if present */
    if (atom->tv) {
        char tv_str[128];
        snprint(tv_str, 128, " <%.3f, %.3f>", atom->tv->strength, atom->tv->confidence);
        strncat(result, tv_str, 1024 - strlen(result) - 1);
    }
    
    return result;
}

Atom*
string_to_atom(char* atom_string, AtomSpaceService* atomspace) {
    /* Simple parser - TODO: Implement full S-expression parser */
    if (!atom_string || !atomspace) return nil;
    
    /* Skip whitespace */
    while (*atom_string == ' ' || *atom_string == '\t' || *atom_string == '\n') {
        atom_string++;
    }
    
    /* Must start with parenthesis */
    if (*atom_string != '(') return nil;
    
    atom_string++;  /* Skip opening parenthesis */
    
    /* Extract type */
    char *type_end = strchr(atom_string, ' ');
    if (!type_end) type_end = strchr(atom_string, ')');
    if (!type_end) return nil;
    
    char type_str[64];
    int type_len = type_end - atom_string;
    if (type_len >= 64) type_len = 63;
    strncpy(type_str, atom_string, type_len);
    type_str[type_len] = '\0';
    
    enum AtomType type = string_to_atom_type(type_str);
    if (type == ATOM_INVALID) return nil;
    
    /* For nodes, extract name if present */
    if (type >= CONCEPT_NODE && type <= TYPED_VARIABLE_NODE) {
        atom_string = type_end;
        while (*atom_string == ' ') atom_string++;
        
        if (*atom_string == '"') {
            atom_string++;  /* Skip opening quote */
            char *name_end = strchr(atom_string, '"');
            if (!name_end) return nil;
            
            char name[256];
            int name_len = name_end - atom_string;
            if (name_len >= 256) name_len = 255;
            strncpy(name, atom_string, name_len);
            name[name_len] = '\0';
            
            return atomspace->add_atom(atomspace, type, name, nil, 0);
        } else {
            return atomspace->add_atom(atomspace, type, nil, nil, 0);
        }
    }
    
    /* TODO: Implement link parsing with recursive outgoing atom parsing */
    return atomspace->add_atom(atomspace, type, nil, nil, 0);
}

int
validate_atom_structure(Atom* atom) {
    if (!atom) return 0;
    
    /* Check type validity */
    if (atom->type <= ATOM_INVALID) return 0;
    
    /* Node-specific validation */
    if (atom->type >= CONCEPT_NODE && atom->type <= TYPED_VARIABLE_NODE) {
        /* Nodes should not have outgoing links */
        if (atom->outgoing_size > 0) return 0;
    }
    
    /* Link-specific validation */
    if (atom->type >= ORDERED_LINK) {
        /* Links should have outgoing atoms */
        if (atom->outgoing_size == 0) return 0;
        
        /* Validate outgoing atoms */
        if (atom->outgoing) {
            int i;
            for (i = 0; i < atom->outgoing_size; i++) {
                if (!validate_atom_structure(atom->outgoing[i])) {
                    return 0;
                }
            }
        }
    }
    
    /* Truth value validation */
    if (atom->tv) {
        if (atom->tv->strength < 0.0 || atom->tv->strength > 1.0) return 0;
        if (atom->tv->confidence < 0.0 || atom->tv->confidence > 1.0) return 0;
        if (atom->tv->count < 0.0) return 0;
    }
    
    return 1;  /* Valid atom */
}

/*
 * Demo Function
 */

void
demo_atom_core(void) {
    print("\n🧬 ATOM CORE DEMO 🧬\n");
    print("══════════════════════\n");
    
    /* Create some atoms */
    Atom *cat = create_atom(CONCEPT_NODE, "cat", nil, 0);
    Atom *animal = create_atom(CONCEPT_NODE, "animal", nil, 0);
    Atom *furry = create_atom(PREDICATE_NODE, "furry", nil, 0);
    
    /* Create a link */
    Atom *outgoing[] = {cat, animal};
    Atom *inheritance = create_atom(INHERITANCE_LINK, nil, outgoing, 2);
    
    /* Set truth values */
    TruthValue *tv1 = create_truth_value(0.9, 0.8, 12.0);
    TruthValue *tv2 = create_truth_value(0.95, 0.9, 20.0);
    
    update_atom_truth_value(cat, tv1);
    update_atom_truth_value(inheritance, tv2);
    
    /* Set attention values */
    AttentionValue *av1 = create_attention_value(100.0, 50.0, 10.0);
    update_atom_attention_value(cat, av1);
    
    /* Display atoms */
    print("\n📝 Created atoms:\n");
    
    char *cat_str = atom_to_string(cat);
    char *animal_str = atom_to_string(animal);
    char *furry_str = atom_to_string(furry);
    char *inheritance_str = atom_to_string(inheritance);
    
    print("  Cat: %s\n", cat_str);
    print("  Animal: %s\n", animal_str);
    print("  Furry: %s\n", furry_str);
    print("  Inheritance: %s\n", inheritance_str);
    
    /* Validate atoms */
    print("\n✅ Atom validation:\n");
    print("  Cat valid: %s\n", validate_atom_structure(cat) ? "Yes" : "No");
    print("  Animal valid: %s\n", validate_atom_structure(animal) ? "Yes" : "No");
    print("  Furry valid: %s\n", validate_atom_structure(furry) ? "Yes" : "No");
    print("  Inheritance valid: %s\n", validate_atom_structure(inheritance) ? "Yes" : "No");
    
    /* Type conversions */
    print("\n🔤 Type string conversions:\n");
    print("  CONCEPT_NODE -> %s\n", atom_type_to_string(CONCEPT_NODE));
    print("  INHERITANCE_LINK -> %s\n", atom_type_to_string(INHERITANCE_LINK));
    print("  \"ConceptNode\" -> %d\n", string_to_atom_type("ConceptNode"));
    print("  \"InheritanceLink\" -> %d\n", string_to_atom_type("InheritanceLink"));
    
    /* Cleanup */
    free(cat_str);
    free(animal_str);
    free(furry_str);
    free(inheritance_str);
    free(tv1);
    free(tv2);
    free(av1);
    
    destroy_atom(inheritance);  /* This will handle the outgoing atoms correctly */
    destroy_atom(cat);
    destroy_atom(animal);
    destroy_atom(furry);
    
    print("\n✅ Atom core demo complete!\n");
}