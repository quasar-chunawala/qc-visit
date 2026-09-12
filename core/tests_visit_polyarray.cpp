#include <iostream>

#include <variant>
#include <random>
#include <array>
#include <string>

#include "visit.h"

template<typename... Callables>
struct Overloaded : Callables...{
    using Callables::operator()...;
};

static std::mt19937 generator(std::random_device{}());
struct Type_1{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_2{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_3{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_4{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_5{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_6{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_7{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_8{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_9{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_10{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_11{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_12{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_13{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_14{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

struct Type_15{
    double value{std::uniform_real_distribution<double>{}(generator)};
};

int sample_uniform_random(int a, int b){
    static std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> dist(a, b);
    return dist(generator);
}

#include <benchmark/benchmark.h>

static void BM_multidim_array_visit_arity_2(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    auto arr = std::array{v1, v2};

    auto visitor = Overloaded{
        [](Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_2) -> size_t { return 1; },
        [](Type_2, Type_1) -> size_t { return 2; },
        [](Type_2, Type_2) -> size_t { return 3; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_2);

static void BM_multidim_array_visit_arity_3(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    auto arr = std::array{v1, v2, v3};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_2, Type_2, Type_2) -> size_t { return 7; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_3);

static void BM_multidim_array_visit_arity_4(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    auto arr = std::array{v1, v2, v3, v4};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_1, Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_1, Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_1, Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_1, Type_2, Type_2, Type_2) -> size_t { return 7; },
        [](Type_2, Type_1, Type_1, Type_1) -> size_t { return 8; },
        [](Type_2, Type_1, Type_1, Type_2) -> size_t { return 9; },
        [](Type_2, Type_1, Type_2, Type_1) -> size_t { return 10; },
        [](Type_2, Type_1, Type_2, Type_2) -> size_t { return 11; },
        [](Type_2, Type_2, Type_1, Type_1) -> size_t { return 12; },
        [](Type_2, Type_2, Type_1, Type_2) -> size_t { return 13; },
        [](Type_2, Type_2, Type_2, Type_1) -> size_t { return 14; },
        [](Type_2, Type_2, Type_2, Type_2) -> size_t { return 15; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_4);

static void BM_multidim_array_visit_arity_5(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    std::variant<Type_1, Type_2> v5{Type_1()};
    auto arr = std::array{v1, v2, v3, v4, v5};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 7; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 8; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 9; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 10; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 11; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 12; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 13; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 14; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 15; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 16; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 17; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 18; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 19; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 20; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 21; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 22; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 23; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 24; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 25; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 26; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 27; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 28; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 29; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 30; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 31; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        std::size_t r5 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_5);

static void BM_multidim_array_visit_arity_6(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    std::variant<Type_1, Type_2> v5{Type_1()};
    std::variant<Type_1, Type_2> v6{Type_2()};
    auto arr = std::array{v1, v2, v3, v4, v5, v6};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 7; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 8; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 9; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 10; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 11; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 12; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 13; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 14; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 15; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 16; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 17; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 18; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 19; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 20; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 21; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 22; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 23; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 24; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 25; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 26; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 27; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 28; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 29; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 30; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 31; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 32; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 33; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 34; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 35; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 36; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 37; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 38; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 39; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 40; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 41; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 42; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 43; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 44; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 45; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 46; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 47; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 48; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 49; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 50; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 51; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 52; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 53; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 54; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 55; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 56; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 57; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 58; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 59; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 60; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 61; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 62; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 63; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        std::size_t r5 = sample_uniform_random(0, 1);
        std::size_t r6 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5], arr[r6]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_6);

static void BM_multidim_array_visit_arity_7(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    std::variant<Type_1, Type_2> v5{Type_1()};
    std::variant<Type_1, Type_2> v6{Type_2()};
    std::variant<Type_1, Type_2> v7{Type_1()};
    auto arr = std::array{v1, v2, v3, v4, v5, v6, v7};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 7; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 8; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 9; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 10; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 11; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 12; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 13; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 14; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 15; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 16; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 17; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 18; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 19; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 20; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 21; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 22; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 23; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 24; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 25; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 26; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 27; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 28; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 29; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 30; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 31; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 32; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 33; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 34; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 35; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 36; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 37; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 38; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 39; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 40; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 41; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 42; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 43; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 44; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 45; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 46; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 47; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 48; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 49; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 50; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 51; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 52; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 53; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 54; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 55; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 56; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 57; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 58; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 59; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 60; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 61; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 62; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 63; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 64; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 65; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 66; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 67; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 68; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 69; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 70; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 71; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 72; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 73; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 74; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 75; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 76; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 77; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 78; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 79; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 80; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 81; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 82; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 83; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 84; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 85; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 86; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 87; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 88; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 89; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 90; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 91; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 92; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 93; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 94; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 95; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 96; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 97; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 98; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 99; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 100; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 101; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 102; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 103; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 104; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 105; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 106; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 107; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 108; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 109; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 110; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 111; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 112; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 113; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 114; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 115; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 116; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 117; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 118; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 119; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 120; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 121; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 122; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 123; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 124; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 125; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 126; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 127; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        std::size_t r5 = sample_uniform_random(0, 1);
        std::size_t r6 = sample_uniform_random(0, 1);
        std::size_t r7 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5], arr[r6], arr[r7]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_7);

static void BM_multidim_array_visit_arity_8(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    std::variant<Type_1, Type_2> v5{Type_1()};
    std::variant<Type_1, Type_2> v6{Type_2()};
    std::variant<Type_1, Type_2> v7{Type_1()};
    std::variant<Type_1, Type_2> v8{Type_2()};
    auto arr = std::array{v1, v2, v3, v4, v5, v6, v7, v8};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 0; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 1; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 2; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 3; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 4; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 5; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 6; },
        [](Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 7; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 8; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 9; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 10; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 11; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 12; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 13; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 14; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 15; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 16; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 17; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 18; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 19; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 20; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 21; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 22; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 23; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 24; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 25; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 26; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 27; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 28; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 29; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 30; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 31; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 32; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 33; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 34; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 35; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 36; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 37; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 38; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 39; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 40; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 41; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 42; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 43; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 44; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 45; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 46; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 47; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 48; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 49; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 50; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 51; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 52; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 53; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 54; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 55; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 56; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 57; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 58; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 59; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 60; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 61; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 62; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 63; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 64; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 65; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 66; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 67; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 68; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 69; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 70; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 71; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 72; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 73; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 74; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 75; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 76; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 77; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 78; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 79; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 80; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 81; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 82; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 83; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 84; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 85; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 86; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 87; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 88; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 89; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 90; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 91; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 92; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 93; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 94; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 95; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 96; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 97; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 98; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 99; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 100; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 101; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 102; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 103; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 104; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 105; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 106; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 107; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 108; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 109; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 110; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 111; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 112; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 113; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 114; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 115; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 116; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 117; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 118; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 119; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 120; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 121; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 122; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 123; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 124; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 125; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 126; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 127; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 128; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 129; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 130; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 131; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 132; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 133; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 134; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 135; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 136; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 137; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 138; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 139; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 140; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 141; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 142; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 143; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 144; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 145; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 146; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 147; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 148; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 149; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 150; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 151; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 152; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 153; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 154; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 155; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 156; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 157; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 158; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 159; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 160; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 161; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 162; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 163; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 164; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 165; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 166; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 167; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 168; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 169; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 170; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 171; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 172; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 173; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 174; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 175; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 176; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 177; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 178; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 179; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 180; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 181; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 182; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 183; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 184; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 185; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 186; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 187; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 188; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 189; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 190; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 191; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 192; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 193; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 194; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 195; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 196; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 197; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 198; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 199; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 200; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 201; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 202; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 203; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 204; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 205; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 206; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 207; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 208; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 209; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 210; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 211; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 212; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 213; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 214; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 215; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 216; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 217; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 218; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 219; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 220; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 221; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 222; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 223; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_1) -> size_t { return 224; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1, Type_2) -> size_t { return 225; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_1) -> size_t { return 226; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2, Type_2) -> size_t { return 227; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_1) -> size_t { return 228; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1, Type_2) -> size_t { return 229; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_1) -> size_t { return 230; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2, Type_2) -> size_t { return 231; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_1) -> size_t { return 232; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1, Type_2) -> size_t { return 233; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_1) -> size_t { return 234; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2, Type_2) -> size_t { return 235; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_1) -> size_t { return 236; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1, Type_2) -> size_t { return 237; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_1) -> size_t { return 238; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2, Type_2) -> size_t { return 239; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_1) -> size_t { return 240; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1, Type_2) -> size_t { return 241; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_1) -> size_t { return 242; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2, Type_2) -> size_t { return 243; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_1) -> size_t { return 244; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1, Type_2) -> size_t { return 245; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_1) -> size_t { return 246; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2, Type_2) -> size_t { return 247; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_1) -> size_t { return 248; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1, Type_2) -> size_t { return 249; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_1) -> size_t { return 250; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2, Type_2) -> size_t { return 251; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_1) -> size_t { return 252; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1, Type_2) -> size_t { return 253; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_1) -> size_t { return 254; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2, Type_2) -> size_t { return 255; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        std::size_t r5 = sample_uniform_random(0, 1);
        std::size_t r6 = sample_uniform_random(0, 1);
        std::size_t r7 = sample_uniform_random(0, 1);
        std::size_t r8 = sample_uniform_random(0, 1);
        auto result = qc::multidim_array::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5], arr[r6], arr[r7], arr[r8]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_multidim_array_visit_arity_8);

BENCHMARK_MAIN();