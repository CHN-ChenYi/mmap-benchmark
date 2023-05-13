# mmap-benchmark

<!-- Depends on [benchmark](https://github.com/google/benchmark). -->
## Compile

### Deps

```shell
git clone https://github.com/google/benchmark
git clone https://github.com/google/googletest.git benchmark/googletest
cd benchmark
mkdir build
cmake -DCMAKE_BUILD_TYPE=RELEASE ..
make -j 4
```

### Build

```shell
make
```

## Run

```shell
./run.sh
```
