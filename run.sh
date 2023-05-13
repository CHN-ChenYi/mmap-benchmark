#/bin/bash
NTIMES=${1:-10}
./mmap-benchmark --benchmark_repetitions=${NTIMES} --benchmark_min_warmup_time=2 --benchmark_min_time=10s --benchmark_out_format=json --benchmark_out=benchmark.json --v=3
