CSRC=MP2.c matrix.c string_ext.c
PROGNAME=mp2
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