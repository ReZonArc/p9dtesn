# Simple Makefile for Kawaii Worker Examples
# Demonstrates building the examples from tutorial 07

TARG=yuki-chan
OFILES=yuki-chan-simple.$O

O=8
CC=8c
LD=8l

$(TARG): $(OFILES)
	$(LD) -o $@ $(OFILES)

%.$O: %.c
	$(CC) $<

clean:
	rm -f *.8 $(TARG)

# Demo targets
demo: $(TARG)
	@echo "Running Yuki-chan demo..."
	@echo "Try commands: hello, status, read /etc/passwd, quit"
	./$(TARG)

test: $(TARG)
	@echo "Testing Yuki-chan with some files..."
	@(echo "hello"; echo "read /etc/passwd"; echo "status"; echo "quit") | ./$(TARG)

.PHONY: demo test clean