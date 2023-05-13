CC=g++
CFLAGS=-O3 -isystem benchmark/include
LDFLAGS=-static -Lbenchmark/build/src -lbenchmark -lpthread

mmap-benchmark: main.cc
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o mmap-benchmark
