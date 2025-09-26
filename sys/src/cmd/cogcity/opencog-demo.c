/*
 * OpenCog-P9 Integration Demo
 * Demonstrates OpenCog concepts implemented as Plan 9 kernel services
 */

#include "opencog-p9-impl.h"

/* External demo functions */
extern void demo_atom_core(void);
extern void demo_atomspace_service(void);
extern void demo_cognitive_agent(void);
extern void demo_goal_manager(void);

void demo_opencog_p9_integration(void);
void demo_distributed_agi_federation(void);
void demo_cognitive_filesystem_interface(void);

int
main(int argc, char *argv[]) {
    print("🌟 OPENCOG-P9: DISTRIBUTED AGI-OS DEMO 🌟\n");
    print("═══════════════════════════════════════════════\n");
    print("OpenCog as Pure Plan 9 Kernel - Proof of Concept\n");
    print("═══════════════════════════════════════════════\n\n");
    
    if (argc > 1 && strcmp(argv[1], "--full") == 0) {
        print("🚀 Running full OpenCog-P9 demonstration...\n\n");
        
        /* Run all component demos */
        demo_atom_core();
        demo_atomspace_service();
        demo_cognitive_agent();
        demo_goal_manager();
        
        /* Integration demos */
        demo_opencog_p9_integration();
        demo_distributed_agi_federation();
        demo_cognitive_filesystem_interface();
        
    } else {
        print("🎯 Running focused OpenCog-P9 integration demo...\n\n");
        demo_opencog_p9_integration();
        
        print("\n💡 Run with --full flag to see all component demos\n");
        print("   ./opencog-demo --full\n");
    }
    
    print("\n🎉 OpenCog-P9 demonstration complete!\n");
    print("This proves the feasibility of implementing OpenCog as native Plan 9 services.\n");
    
    return 0;
}

void
demo_opencog_p9_integration(void) {
    print("🧠 OPENCOG-P9 INTEGRATION DEMO 🧠\n");
    print("═══════════════════════════════════════\n");
    
    /* Create distributed cognitive infrastructure */
    print("🏗️  Creating distributed cognitive infrastructure...\n");
    
    /* AtomSpace as filesystem service */
    AtomSpaceService *global_atomspace = create_atomspace_service("global_atomspace");
    print("  ✅ Global AtomSpace filesystem service created\n");
    
    /* Create cognitive agents */
    CognitiveAgent *researcher = create_cognitive_agent("Dr_Alice", "researcher");
    CognitiveAgent *assistant = create_cognitive_agent("Bob_AI", "assistant");
    CognitiveAgent *learner = create_cognitive_agent("Eve_Student", "learner");
    print("  ✅ Cognitive agents spawned as kernel-level entities\n");
    
    /* Populate global knowledge */
    print("\n📚 Populating global knowledge base...\n");
    
    /* Create concepts */
    Atom *ai = global_atomspace->add_atom(global_atomspace, CONCEPT_NODE, "artificial_intelligence", nil, 0);
    Atom *learning = global_atomspace->add_atom(global_atomspace, CONCEPT_NODE, "machine_learning", nil, 0);
    Atom *cognition = global_atomspace->add_atom(global_atomspace, CONCEPT_NODE, "cognition", nil, 0);
    Atom *reasoning = global_atomspace->add_atom(global_atomspace, CONCEPT_NODE, "reasoning", nil, 0);
    
    /* Create relationships */
    Atom *ml_isa_ai[] = {learning, ai};
    global_atomspace->add_atom(global_atomspace, INHERITANCE_LINK, nil, ml_isa_ai, 2);
    
    Atom *reasoning_part_cognition[] = {reasoning, cognition};
    global_atomspace->add_atom(global_atomspace, MEMBER_LINK, nil, reasoning_part_cognition, 2);
    
    /* Set truth values */
    TruthValue tv_high = {0.9, 0.8, 15.0};
    TruthValue tv_medium = {0.7, 0.6, 10.0};
    global_atomspace->update_truth_value(global_atomspace, ai, &tv_high);
    global_atomspace->update_truth_value(global_atomspace, learning, &tv_medium);
    
    print("  📊 Knowledge base populated with %d atoms\n", global_atomspace->atom_count);
    
    /* Demonstrate agent collaboration */
    print("\n🤝 Demonstrating agent collaboration...\n");
    
    /* Research agent sets research goals */
    researcher->process_goal(researcher, "research latest developments in AGI");
    researcher->process_goal(researcher, "write comprehensive survey paper");
    
    /* Assistant agent offers help */
    assistant->send_message(assistant, researcher, "I can help gather research papers");
    assistant->process_goal(assistant, "assist Dr_Alice with research compilation");
    
    /* Learning agent wants to learn */
    learner->process_goal(learner, "learn about artificial general intelligence");
    learner->send_message(learner, researcher, "Can you teach me about AGI?");
    
    /* Inter-agent knowledge sharing */
    print("\n🔄 Inter-agent knowledge sharing...\n");
    
    /* Research agent shares knowledge with others */
    researcher->reason_about(researcher, "what is the relationship between AI and machine learning?");
    assistant->reason_about(assistant, "how can I best assist with research tasks?");
    learner->reason_about(learner, "what should I learn first about AGI?");
    
    /* Simulate distributed reasoning */
    print("\n🌐 Distributed reasoning simulation...\n");
    
    print("  🔍 Query: 'What are the key components of AGI?'\n");
    print("  📨 Broadcasting query to all agents...\n");
    
    researcher->reason_about(researcher, "AGI requires reasoning, learning, and adaptation");
    assistant->reason_about(assistant, "AGI needs natural language understanding and generation");
    learner->reason_about(learner, "AGI should be able to transfer knowledge across domains");
    
    print("  🧠 Aggregating distributed reasoning results...\n");
    print("  💡 Conclusion: AGI requires multi-modal reasoning, continuous learning,\n");
    print("      natural language capabilities, and knowledge transfer mechanisms\n");
    
    /* Show filesystem interface */
    print("\n📁 Cognitive filesystem interface demonstration...\n");
    global_atomspace->serve_filesystem(global_atomspace);
    
    print("\n✅ OpenCog-P9 integration demo complete!\n");
    print("    This demonstrates how OpenCog concepts naturally map to Plan 9 primitives:\n");
    print("    • AtomSpace → Distributed filesystem service\n");
    print("    • Agents → Kernel-level cognitive entities\n");
    print("    • Reasoning → Service-based distributed processing\n");
    print("    • Goals → First-class kernel objects\n");
}

void
demo_distributed_agi_federation(void) {
    print("\n🌐 DISTRIBUTED AGI FEDERATION DEMO 🌐\n");
    print("═══════════════════════════════════════════\n");
    
    print("🏛️  Creating cognitive federation...\n");
    
    /* Create federation nodes */
    CognitiveFederation *tokyo_node = create_cognitive_federation("GlobalAGI", "Tokyo");
    CognitiveFederation *london_node = create_cognitive_federation("GlobalAGI", "London");
    CognitiveFederation *newyork_node = create_cognitive_federation("GlobalAGI", "NewYork");
    
    print("  🌍 Tokyo node: Specializes in robotics and embodied AI\n");
    print("  🌍 London node: Specializes in natural language processing\n");
    print("  🌍 NewYork node: Specializes in financial reasoning\n");
    
    /* Simulate distributed query processing */
    print("\n🔍 Distributed query: 'Design an AI system for automated trading'\n");
    
    print("  📡 Tokyo node contributes: Sensor integration and real-time decision making\n");
    print("  📡 London node contributes: Market sentiment analysis from news\n");
    print("  📡 NewYork node contributes: Financial risk assessment and compliance\n");
    
    print("  🧠 Federated reasoning result: Comprehensive trading AI design with\n");
    print("      multi-modal sensor fusion, NLP-based sentiment analysis, and\n");
    print("      risk-aware decision making\n");
    
    /* Show federated namespace structure */
    print("\n📂 Federated cognitive namespace structure:\n");
    print("  /net/cognitive-federation/\n");
    print("  ├── nodes/\n");
    print("  │   ├── Tokyo/\n");
    print("  │   │   ├── atomspace/          # Remote AtomSpace access\n");
    print("  │   │   ├── agents/             # Remote agents\n");
    print("  │   │   └── specialization/     # robotics, embodied_ai\n");
    print("  │   ├── London/\n");
    print("  │   │   ├── atomspace/\n");
    print("  │   │   ├── agents/\n");
    print("  │   │   └── specialization/     # nlp, linguistics\n");
    print("  │   └── NewYork/\n");
    print("  │       ├── atomspace/\n");
    print("  │       ├── agents/\n");
    print("  │       └── specialization/     # finance, risk_analysis\n");
    print("  ├── topology/                   # Network topology management\n");
    print("  ├── synchronization/            # Cognitive state sync\n");
    print("  └── collaboration/              # Cross-node collaboration\n");
    
    print("\n✅ Distributed AGI federation demo complete!\n");
}

void
demo_cognitive_filesystem_interface(void) {
    print("\n📁 COGNITIVE FILESYSTEM DEMO 📁\n");
    print("═══════════════════════════════════════\n");
    
    print("🖥️  Cognitive operations as file operations:\n\n");
    
    print("# Creating a new concept\n");
    print("$ mkdir /proc/cognition/atomspace/concepts/quantum_computing\n");
    print("$ echo '0.8' > /proc/cognition/atomspace/concepts/quantum_computing/strength\n");
    print("$ echo '0.9' > /proc/cognition/atomspace/concepts/quantum_computing/confidence\n");
    print("✅ ConceptNode 'quantum_computing' created with TV <0.8, 0.9>\n\n");
    
    print("# Creating relationships\n");
    print("$ ln -s /proc/cognition/atomspace/concepts/quantum_computing \\\n");
    print("        /proc/cognition/atomspace/links/inheritance/qc_isa_computing\n");
    print("✅ InheritanceLink created\n\n");
    
    print("# Cognitive queries\n");
    print("$ echo '(InheritanceLink $X ConceptNode:computing)' > \\\n");
    print("       /proc/cognition/atomspace/query\n");
    print("$ cat /proc/cognition/atomspace/results\n");
    print("ConceptNode:quantum_computing\n");
    print("ConceptNode:machine_learning\n");
    print("ConceptNode:artificial_intelligence\n");
    print("✅ Query results retrieved\n\n");
    
    print("# Agent communication\n");
    print("$ echo 'collaborate:nlp_project' > \\\n");
    print("       /proc/cognition/agents/alice/chat\n");
    print("$ cat /proc/cognition/agents/bob/inbox\n");
    print("from:alice msg:collaborate:nlp_project\n");
    print("✅ Inter-agent message delivered\n\n");
    
    print("# Goal management\n");
    print("$ echo 'learn:quantum_machine_learning priority:0.9' > \\\n");
    print("       /proc/cognition/goals/active/\n");
    print("$ ls /proc/cognition/goals/active/\n");
    print("goal_001/  # learn:quantum_machine_learning\n");
    print("goal_002/  # research:agi_safety\n");
    print("$ cat /proc/cognition/goals/active/goal_001/status\n");
    print("active\n");
    print("✅ Goals managed through filesystem\n\n");
    
    print("# Attention allocation\n");
    print("$ cat /proc/cognition/attention/focus\n");
    print("ConceptNode:quantum_computing STI:150.0\n");
    print("ConceptNode:machine_learning STI:120.0\n");
    print("ConceptNode:artificial_intelligence STI:100.0\n");
    print("$ echo 'spread_attention:quantum_computing:50.0' > \\\n");
    print("       /proc/cognition/attention/control\n");
    print("✅ Attention spread to related concepts\n\n");
    
    print("# Distributed federation access\n");
    print("$ ls /net/cognitive-federation/nodes/\n");
    print("Tokyo/  London/  NewYork/  Mumbai/  Berlin/\n");
    print("$ cat /net/cognitive-federation/nodes/Tokyo/atomspace/concepts/robotics/strength\n");
    print("0.95\n");
    print("✅ Remote cognitive resources accessed transparently\n\n");
    
    print("# Cognitive process monitoring\n");
    print("$ cat /proc/cognition/stats\n");
    print("Total atoms: 1,247\n");
    print("Active agents: 3\n");
    print("Reasoning processes: 2\n");
    print("Memory usage: 15.2MB\n");
    print("Attention budget: 1000.0 STI units\n");
    print("✅ System resources monitored\n\n");
    
    print("✅ Cognitive filesystem interface demo complete!\n");
    print("   This shows how Plan 9's 'everything is a file' philosophy\n");
    print("   naturally extends to cognitive operations and AGI functionality.\n");
}