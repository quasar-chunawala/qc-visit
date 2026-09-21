#!/usr/bin/bash

# Run gc++ builds and benchmark the code

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_flat_array.cpp -lbenchmark -lpthread -o bench_flat_array

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_polyarray.cpp -lbenchmark -lpthread -o bench_polyarray_gcc

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_stdlib.cpp -lbenchmark -lpthread -o bench_stdlib_gcc