# from the qc-visit root (where you ran `ls -R`)

# libstdc++ builds
clang++ -std=c++23 -O3 -DNDEBUG -stdlib=libstdc++ -Icore \
    core/tests_visit_libcpp.cpp -lbenchmark -lpthread \
    -o bench_libcpp_libstdcxx

clang++ -std=c++23 -O3 -DNDEBUG -stdlib=libstdc++ -Icore \
    core/tests_visit_polyarray.cpp -lbenchmark -lpthread \
    -o bench_polyarray_libstdcxx

clang++ -std=c++23 -O3 -DNDEBUG -stdlib=libstdc++ -Icore \
    core/tests_visit_flat_array.cpp -lbenchmark -lpthread \
    -o bench_flat_array_libstdcxx