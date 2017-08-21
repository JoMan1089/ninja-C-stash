CSRC=vector.c MP1.c string_ext.c safe_input.c
PROGNAME=mp1
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