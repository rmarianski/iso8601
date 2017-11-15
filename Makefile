P=iso8601
OBJECTS=$(P).o
CFLAGS = -g -Wall -std=gnu11 -pedantic -O3 `pkg-config --cflags ramutils`
LDLIBS = `pkg-config --libs ramutils`

$(P): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(P)

install $(P):
	cp $(P) $(HOME)/bin/

.PHONY: clean
