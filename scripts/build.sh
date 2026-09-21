#!/usr/bin/bash

# Run gc++ builds and benchmark the code

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_flat_array.cpp -lbenchmark -lpthread -o bench_flat_array

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_polyarray.cpp -lbenchmark -lpthread -o bench_visit_polyarray

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_stdlib.cpp -lbenchmark -lpthread -o bench_visit_libstdcxx

g++ -std=c++23 -O2 -DNDEBUG -Icore core/tests_visit_mdspan_impl.cpp -lbenchmark -lpthread -o bench_visit_mdspan_impl

# We must build google benchmark by linking it against libc++,
# instead of libstdc++, to measure libcxx visit performance.
git clone --depth 1 --branch v1.9.1 https://github.com/google/benchmark.git
sed -i '/add_cxx_compiler_flag(-pedantic-errors)/d' benchmark/CMakeLists.txt

cmake -S benchmark -B benchmark/build_libcxx -G Ninja \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_CXX_FLAGS="-stdlib=libc++" \
  -DCMAKE_EXE_LINKER_FLAGS="-stdlib=libc++" \
  -DBENCHMARK_ENABLE_TESTING=OFF \
  -DBENCHMARK_ENABLE_WERROR=OFF \
  -DCMAKE_BUILD_TYPE=Release
cmake --build benchmark/build_libcxx -j$(nproc)

# Your actual benchmark, now against the libc++ build
clang++ -std=c++23 -stdlib=libc++ -O2 -DNDEBUG \
  -Icore -I benchmark/include \
  core/tests_visit_stdlib.cpp \
  -L benchmark/build_libcxx/src -lbenchmark \
  -lpthread \
  -o bench_visit_libcxx