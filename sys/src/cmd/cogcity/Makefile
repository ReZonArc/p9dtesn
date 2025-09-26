# Cognitive Cities Foundry Makefile
# Build system for the advanced distributed cognition system

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I. -DLINUX_BUILD
LDFLAGS = -lm -lpthread
YACC = yacc
LEX = lex

TARGET = cogcity
SOURCES = main.c cogcity.c lexer.c y.tab.c plan9_compat.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = cogcity.h y.tab.h plan9_compat.h

# Generate parser from grammar
y.tab.c y.tab.h: grammar.y
	$(YACC) -d grammar.y

# Build main target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile object files
main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

cogcity.o: cogcity.c $(HEADERS)
	$(CC) $(CFLAGS) -c cogcity.c

lexer.o: lexer.c $(HEADERS)
	$(CC) $(CFLAGS) -c lexer.c

y.tab.o: y.tab.c y.tab.h cogcity.h
	$(CC) $(CFLAGS) -c y.tab.c

plan9_compat.o: plan9_compat.c plan9_compat.h
	$(CC) $(CFLAGS) -c plan9_compat.c

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET) y.tab.c y.tab.h y.output

# Install (demo)
install: $(TARGET)
	@echo "Cognitive Cities Foundry built successfully!"
	@echo "Run ./$(TARGET) -d for demo mode"
	@echo "Run ./$(TARGET) -i for interactive mode"

# Demo target
demo: $(TARGET)
	./$(TARGET) -d -c "CyberTokyo"

# Interactive target
interactive: $(TARGET)
	./$(TARGET) -i -c "NeoShanghai"

# Help
help:
	@echo "Cognitive Cities Foundry Build System"
	@echo "====================================="
	@echo "Targets:"
	@echo "  all       - Build the cognitive cities system"
	@echo "  clean     - Remove build artifacts"
	@echo "  demo      - Build and run demo mode"
	@echo "  interactive - Build and run interactive mode"
	@echo "  help      - Show this help"
	@echo ""
	@echo "The system demonstrates:"
	@echo "  • Tensor bundle channel multiplexing"
	@echo "  • Namespace event loops with transformer activation"
	@echo "  • Network hypergraph queries and modifications"
	@echo "  • Hopf fibration topology resolution"
	@echo "  • YACC-based cognitive grammar parsing"
	@echo "  • Interactive chat interface"

.PHONY: clean install demo interactive help all
.DEFAULT_GOAL := $(TARGET)