#include <benchmark/benchmark.h>
#include <sys/mman.h>

template <size_t size>
static void MMAP(benchmark::State& state) {
  // Perform setup here
  char* buf;
  for (auto _ : state) {
    // This code gets timed
    buf = reinterpret_cast<char*>(mmap(NULL, size, PROT_READ | PROT_WRITE,
                                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    for (size_t i = 0; i < size; i += 0x1000) {
      buf[i] = 'A';  // Touch every page.
      if (buf[i] != 'A') {
        state.SkipWithError("Failed to read data from allocated page.");
        return;  // Needed to skip the rest of the iteration.
      }
    }
    munmap(buf, size);
  }
}

// Register the function as a benchmark
BENCHMARK(MMAP<0x1000>);      // 4KB
BENCHMARK(MMAP<0x200000>);    // 2MB
BENCHMARK(MMAP<0x40000000>);  // 1GB

// Run the benchmark
BENCHMARK_MAIN();
