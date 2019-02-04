CC=gcc
IDIR =include
SDIR =src
ODIR =build
CFLAGS=-I$(IDIR)

_OBJ = driver.o linkedlist.o stack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = linkedlist.h stack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all : run

run : memory
	./memory

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

memory : ${OBJ}
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean all run

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
