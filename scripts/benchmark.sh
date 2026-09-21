#!/usr/bin/bash
sudo chrt -f 10 taskset -c 3 ./bench_flat_array \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=flat_array_results.json \
    --benchmark_out_format=json

sudo chrt -f 10 taskset -c 3 ./bench_visit_polyarray \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=polyarray_results.json \
    --benchmark_out_format=json  

sudo chrt -f 10 taskset -c 3 ./bench_visit_libstdcxx \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=libstdcxx_results.json \
    --benchmark_out_format=json    

sudo chrt -f 10 taskset -c 3 ./bench_visit_libcxx \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=libcxx_results.json \
    --benchmark_out_format=json    

sudo chrt -f 10 taskset -c 3 ./bench_visit_mdspan_impl \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=mdspan_impl_results.json \
    --benchmark_out_format=json        