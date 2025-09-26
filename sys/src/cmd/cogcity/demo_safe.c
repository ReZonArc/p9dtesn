#include "cogcity.h"

/*
 * Safe Cognitive Cities Demo - No Threading Version
 * Demonstrates the core functionality without complex threading
 */

extern CognitiveCity *global_cognitive_city;

void
safe_demo_all(CognitiveCity *city) {
    print("🌟 COGNITIVE CITIES FOUNDRY - SAFE DEMO MODE 🌟\n");
    print("═══════════════════════════════════════════════════\n");
    
    // Demo 1: Tensor Bundle Operations
    print("\n═══ 📡 TENSOR BUNDLE MULTIPLEXING ═══\n");
    TensorBundle *tb = city->tensor_bundles[0];
    if (tb) {
        print("Tensor Bundle ID: %d\n", tb->id);
        print("Dimensions: %d, Channels: %d\n", tb->dimensions, tb->channel_count);
        
        // Fill with sample data
        for (int i = 0; i < tb->dimensions; i++) {
            tb->data[i] = sin(i * 3.14159 / 4.0);
        }
        
        // Show transformation capabilities
        print("Sample tensor operations complete ✅\n");
    }
    
    // Demo 2: Network Hypergraph
    print("\n═══ 🕸️  NETWORK HYPERGRAPH OPERATIONS ═══\n");
    NetworkHypergraph *hg = city->network;
    if (hg) {
        hg->query_structure(hg, "nodes");
        hg->modify_topology(hg, "add_node demo_worker");
        hg->query_structure(hg, "connectivity");
        print("Hypergraph operations complete ✅\n");
    }
    
    // Demo 3: Cognitive Grammar
    print("\n═══ 🧠 COGNITIVE GRAMMAR PARSING ═══\n");
    if (city->inference && city->inference->grammar) {
        char *test_commands[] = {
            "query hypergraph nodes",
            "optimize resources",
            "chat \"Hello, cognitive city!\"",
            NULL
        };
        
        for (int i = 0; test_commands[i]; i++) {
            print("Parsing: %s\n", test_commands[i]);
            if (city->inference->grammar->validate_syntax(city->inference->grammar, test_commands[i])) {
                print("  ✅ Valid syntax\n");
            } else {
                print("  ❌ Invalid syntax\n");
            }
        }
        print("Grammar parsing complete ✅\n");
    }
    
    // Demo 4: Inference Engine
    print("\n═══ 🧮 INFERENCE ENGINE REASONING ═══\n");
    if (city->inference) {
        city->inference->reason(city->inference, "What is the cognitive density of this city?");
        print("Inference reasoning complete ✅\n");
    }
    
    // Demo 5: Topology Resolution
    print("\n═══ 🌐 HOPF FIBRATION TOPOLOGY ═══\n");
    HopfFibration *hf = city->topology_resolver;
    if (hf) {
        print("Base space dimensions: %d\n", hf->base_space_dim);
        print("Fiber space dimensions: %d\n", hf->fiber_space_dim);
        print("Total space dimensions: %d\n", hf->total_space_dim);
        
        hf->resolve_partition(hf, "demo_namespace_conflict");
        hf->check_crossing(hf, "partition_a", "partition_b");
        print("Topology resolution complete ✅\n");
    }
    
    // Demo 6: Resource Optimization
    print("\n═══ ⚡ RESOURCE OPTIMIZATION ═══\n");
    city->optimize_resources(city);
    print("Resource optimization complete ✅\n");
    
    // Demo 7: Zero-Security Execution
    print("\n═══ 🔓 ZERO-SECURITY EXECUTION ═══\n");
    execute_in_zero_security_env(city, "analyze_cognitive_patterns");
    execute_in_zero_security_env(city, "optimize_tensor_channels");
    print("Zero-security execution complete ✅\n");
    
    print("\n🎉 All cognitive cities demonstrations completed successfully! 🎉\n");
    print("City: %s\n", city->city_name);
    print("Population: %d\n", city->population);
    print("Cognitive Density: %.2f\n", city->cognitive_density);
}

void
interactive_safe_demo(CognitiveCity *city) {
    print("\n═══ 💬 INTERACTIVE COGNITIVE INTERFACE ═══\n");
    print("Simulating interactive session with %s...\n", city->city_name);
    
    char *demo_interactions[] = {
        "query hypergraph connectivity",
        "modify namespace partition core_system", 
        "tensor multiplex channel tensor_bundle_1",
        "create inference reasoning advanced_cognition",
        "chat \"Analyze the current network topology\"",
        "optimize resources in namespace inference",
        "optimize zero-security execution environment",
        NULL
    };
    
    for (int i = 0; demo_interactions[i]; i++) {
        print("\n🏙️  %s> %s\n", city->city_name, demo_interactions[i]);
        
        // Process through cognitive grammar
        if (city->inference && city->inference->grammar) {
            city->inference->grammar->parse_sentence(city->inference->grammar, demo_interactions[i]);
        }
        
        // Process as citizen request
        city->process_citizen_request(city, demo_interactions[i]);
        
        print("   Response: Command processed by cognitive infrastructure\n");
    }
    
    print("\n✅ Interactive demo session complete!\n");
}

int
main(int argc, char *argv[]) {
    (void)argc; (void)argv; // Suppress warnings
    
    print("🌟 SAFE COGNITIVE CITIES FOUNDRY DEMO 🌟\n");
    print("Advanced distributed cognition without complex threading\n");
    print("═════════════════════════════════════════════════════\n\n");
    
    // Create the cognitive city
    global_cognitive_city = create_cognitive_city("NeoTokyo-Safe");
    
    if (!global_cognitive_city) {
        print("❌ Failed to create cognitive city\n");
        return 1;
    }
    
    print("🚀 Cognitive city '%s' operational!\n", global_cognitive_city->city_name);
    
    // Run safe demonstrations
    safe_demo_all(global_cognitive_city);
    
    // Run interactive demo
    interactive_safe_demo(global_cognitive_city);
    
    print("\n🌟 Cognitive Cities Foundry demonstration complete! 🌟\n");
    print("This system demonstrates:\n");
    print("  • Tensor bundle channel multiplexing\n");
    print("  • YACC-based cognitive grammar parsing\n");
    print("  • Network hypergraph topology analysis\n");
    print("  • Hopf fibration namespace resolution\n");
    print("  • Advanced inference engine reasoning\n");
    print("  • Zero-security execution environments\n");
    print("  • Interactive cognitive chat interfaces\n");
    
    return 0;
}