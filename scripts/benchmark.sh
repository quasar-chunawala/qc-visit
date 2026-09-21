#!/usr/bin/bash
sudo chrt -f 10 taskset -c 3 ./bench_flat_array \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=flat_array_results.json \
    --benchmark_out_format=json

sudo chrt -f 10 taskset -c 3 ./bench_stdlib_gcc \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=stdlib_results.json \
    --benchmark_out_format=json    