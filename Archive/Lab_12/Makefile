CSRC=ME12.c safe_input.c string_ext.c
PROGNAME=ME12
CC=gcc
CFLAGS=-W -Wall
LFLAGS=-lm
OBJECTS=$(CSRC:.c=.o)
all: $(PROGNAME)
.PHONY: clean
$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(PROGNAME)
clean:
	rm -f $(OBJECTS)
	rm -f $(PROGNAME)