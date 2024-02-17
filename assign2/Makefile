ifeq (, $(shell which jemalloc-config))
JEMALLOC =
else
JEMALLOC = -L$(JEMALLOCLD) -ljemalloc 
endif

CC=g++
CFLAGS = -O3 -std=c++17 -pthread

hotspots: hotspots.cpp hotspots.h
	$(CC) $(CFLAGS) $(JEMALLOC) -I parlaylib/include/ -o hotspots hotspots.cpp

install:
	wget http://www.cs.cmu.edu/~parlay/graph_data.tar.bz2
	tar -xjf graph_data.tar.bz2
	rm graph_data.tar.bz2
	git clone git@github.com:cmuparlay/parlaylib.git


runsmall: hotspots
	./hotspots 100

runlarge: hotspots
	./hotspots graph_data/com_orkut_sym.adj
