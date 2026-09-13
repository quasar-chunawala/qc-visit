# from the qc-visit root (where you ran `ls -R`)

# Run gc++ builds and benchmark the code

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_flat_array.cpp -lbenchmark -lpthread -o bench_flat_array
sudo chrt -f 10 taskset -c 3 ./bench_flat_array \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=flat_array_results_v2.json \
    --benchmark_out_format=json

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_polyarray.cpp -lbenchmark -lpthread -o bench_polyarray_gcc
./bench_polyarray_gcc --benchmark_min_time=1.0s --benchmark_repetitions=30 --benchmark_out=polyarray_results.json --benchmark_out_format=json

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_stdlib.cpp -lbenchmark -lpthread -o bench_stdlib_gcc
sudo chrt -f 10 taskset -c 3 ./bench_stdlib_gcc \
    --benchmark_min_time=2.0s \
    --benchmark_repetitions=30 \
    --benchmark_out=stdlib_results_v1.json \
    --benchmark_out_format=json