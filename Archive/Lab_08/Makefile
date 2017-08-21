CSRC=string_ext.c ME8.c
PROGNAME=me8
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