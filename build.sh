# from the qc-visit root (where you ran `ls -R`)

# gc++ builds

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_flat_array.cpp -lbenchmark -lpthread -o bench_flat_array
./bench_flat_array --benchmark_min_time=1.0s --benchmark_repetitions=20

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_polyarray.cpp -lbenchmark -lpthread -o bench_polyarray_gcc
./bench_polyarray_gcc --benchmark_min_time=1.0s --benchmark_repetitions=20

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_stdlib.cpp -lbenchmark -lpthread -o bench_stdlib_gcc
./bench_stdlib_gcc --benchmark_min_time=1.0s --benchmark_repetitions=20