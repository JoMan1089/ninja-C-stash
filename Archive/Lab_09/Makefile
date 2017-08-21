CSRC=gol.c ME9.c
PROGNAME=me9
CC=gcc
CFLAGS=-W -Wall
LFLAGS=-lm
OBJECTS=$(CSRC:.c=.o)
all: $(PROGNAME)
.PHONY: clean
$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECTS) -o $(PROGNAME)
clean:
	rm -f $(OBJECTS)
	rm -f $(PROGNAME)