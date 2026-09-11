#include <variant>
#include <random>
#include <array>
#include <iostream>

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

auto test_variants_size_2_arity_2(){
    std::variant<Type_1, Type_2> v1{ Type_1() };
    std::variant<Type_1, Type_2> v2{ Type_2() };
    auto arr = std::array{v1, v2};

    std::size_t r1 = sample_uniform_random(0,1);
    std::size_t r2 = sample_uniform_random(0,1);

    std::visit(Overloaded{
        [](Type_1, Type_1)->std::string { return "(Type_1, Type_1)"; },
        [](Type_1, Type_2)->std::string { return "(Type_1, Type_2)"; },
        [](Type_2, Type_1)-> std::string{ return "(Type_2, Type_1)"; },
        [](Type_2, Type_2)-> std::string{ return "(Type_2, Type_2)"; }
    }, arr[r1], arr[r2]);
}

auto test_variants_size_2_arity_3(){
    std::variant<Type_1, Type_2> v1{ Type_1() };
    std::variant<Type_1, Type_2> v2{ Type_2() };
    std::variant<Type_1, Type_2> v3{ Type_1() };
    auto arr = std::array{v1, v2, v3};

    std::size_t r1 = sample_uniform_random(0,1);
    std::size_t r2 = sample_uniform_random(0,1);
    std::size_t r3 = sample_uniform_random(0,1);

    std::visit(Overloaded{
        [](Type_1, Type_1, Type_1)->std::string { return "(Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_2)->std::string { return "(Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_1)->std::string { return "(Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2)->std::string { return "(Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1)->std::string { return "(Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_2)->std::string { return "(Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_1)->std::string { return "(Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2)->std::string { return "(Type_2, Type_2, Type_2)"; },
    }, arr[r1], arr[r2], arr[r3]);
}

auto test_variants_size_2_arity_4(){
    std::variant<Type_1, Type_2> v1{ Type_1() };
    std::variant<Type_1, Type_2> v2{ Type_2() };
    std::variant<Type_1, Type_2> v3{ Type_1() };
    std::variant<Type_1, Type_2> v4{ Type_2() };
    auto arr = std::array{v1, v2, v3, v4};

    std::size_t r1 = sample_uniform_random(0,1);
    std::size_t r2 = sample_uniform_random(0,1);
    std::size_t r3 = sample_uniform_random(0,1);
    std::size_t r4 = sample_uniform_random(0,1);

    std::visit(Overloaded{
        [](Type_1, Type_1, Type_1, Type_1)->std::string { return "(Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_2)->std::string { return "(Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_1)->std::string { return "(Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_2)->std::string { return "(Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_1)->std::string { return "(Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_2)->std::string { return "(Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_1)->std::string { return "(Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_2)->std::string { return "(Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_1)->std::string { return "(Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_2)->std::string { return "(Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_1)->std::string { return "(Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_2)->std::string { return "(Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_1)->std::string { return "(Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_2)->std::string { return "(Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_1)->std::string { return "(Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_2)->std::string { return "(Type_2, Type_2, Type_2, Type_2)"; },
    }, arr[r1], arr[r2], arr[r3], arr[r4]);
}

auto test_variants_size_2_arity_5(){
    std::variant<Type_1, Type_2> v1{ Type_1() };
    std::variant<Type_1, Type_2> v2{ Type_2() };
    std::variant<Type_1, Type_2> v3{ Type_1() };
    std::variant<Type_1, Type_2> v4{ Type_2() };
    std::variant<Type_1, Type_2> v5{ Type_1() };
    auto arr = std::array{v1, v2, v3, v4, v5};

    std::size_t r1 = sample_uniform_random(0,1);
    std::size_t r2 = sample_uniform_random(0,1);
    std::size_t r3 = sample_uniform_random(0,1);
    std::size_t r4 = sample_uniform_random(0,1);
    std::size_t r5 = sample_uniform_random(0,1);

    std::visit(Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1)->std::string { return "(Type_1, Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2)->std::string { return "(Type_1, Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1)->std::string { return "(Type_1, Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2)->std::string { return "(Type_1, Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1)->std::string { return "(Type_1, Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2)->std::string { return "(Type_1, Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1)->std::string { return "(Type_1, Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2)->std::string { return "(Type_1, Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1)->std::string { return "(Type_1, Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2)->std::string { return "(Type_1, Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1)->std::string { return "(Type_1, Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2)->std::string { return "(Type_1, Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1)->std::string { return "(Type_1, Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2)->std::string { return "(Type_1, Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1)->std::string { return "(Type_1, Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2)->std::string { return "(Type_1, Type_2, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1)->std::string { return "(Type_2, Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2)->std::string { return "(Type_2, Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1)->std::string { return "(Type_2, Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2)->std::string { return "(Type_2, Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1)->std::string { return "(Type_2, Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2)->std::string { return "(Type_2, Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1)->std::string { return "(Type_2, Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2)->std::string { return "(Type_2, Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1)->std::string { return "(Type_2, Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2)->std::string { return "(Type_2, Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1)->std::string { return "(Type_2, Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2)->std::string { return "(Type_2, Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1)->std::string { return "(Type_2, Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2)->std::string { return "(Type_2, Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1)->std::string { return "(Type_2, Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2)->std::string { return "(Type_2, Type_2, Type_2, Type_2, Type_2)"; },
    }, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5]);
}

// --- Append to tests_visit_libcpp.cpp ---
//
// Same shape as the flat_array version: variant array constructed once
// outside the timed loop, only random-index sampling + std::visit dispatch
// happens inside. No lambda-return bug here (this file's lambdas already
// `return` correctly), so no fix needed -- just wrapping the existing
// dispatch pattern in benchmark::State loops.

#include <benchmark/benchmark.h>

static void BM_std_visit_arity_2(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    auto arr = std::array{v1, v2};

    auto visitor = Overloaded{
        [](Type_1, Type_1) -> std::string { return "(Type_1, Type_1)"; },
        [](Type_1, Type_2) -> std::string { return "(Type_1, Type_2)"; },
        [](Type_2, Type_1) -> std::string { return "(Type_2, Type_1)"; },
        [](Type_2, Type_2) -> std::string { return "(Type_2, Type_2)"; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        auto result = std::visit(visitor, arr[r1], arr[r2]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_std_visit_arity_2);

static void BM_std_visit_arity_3(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    auto arr = std::array{v1, v2, v3};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1) -> std::string { return "(Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_2) -> std::string { return "(Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_1) -> std::string { return "(Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2) -> std::string { return "(Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1) -> std::string { return "(Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_2) -> std::string { return "(Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_1) -> std::string { return "(Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2) -> std::string { return "(Type_2, Type_2, Type_2)"; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        auto result = std::visit(visitor, arr[r1], arr[r2], arr[r3]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_std_visit_arity_3);

static void BM_std_visit_arity_4(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    auto arr = std::array{v1, v2, v3, v4};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1) -> std::string { return "(Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_2) -> std::string { return "(Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_1) -> std::string { return "(Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_2) -> std::string { return "(Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_1) -> std::string { return "(Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_2) -> std::string { return "(Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_1) -> std::string { return "(Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_2) -> std::string { return "(Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_1) -> std::string { return "(Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_2) -> std::string { return "(Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_1) -> std::string { return "(Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_2) -> std::string { return "(Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_1) -> std::string { return "(Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_2) -> std::string { return "(Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_1) -> std::string { return "(Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_2) -> std::string { return "(Type_2, Type_2, Type_2, Type_2)"; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        auto result = std::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_std_visit_arity_4);

static void BM_std_visit_arity_5(benchmark::State& state) {
    std::variant<Type_1, Type_2> v1{Type_1()};
    std::variant<Type_1, Type_2> v2{Type_2()};
    std::variant<Type_1, Type_2> v3{Type_1()};
    std::variant<Type_1, Type_2> v4{Type_2()};
    std::variant<Type_1, Type_2> v5{Type_1()};
    auto arr = std::array{v1, v2, v3, v4, v5};

    auto visitor = Overloaded{
        [](Type_1, Type_1, Type_1, Type_1, Type_1) -> std::string { return "(Type_1, Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_1, Type_2) -> std::string { return "(Type_1, Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_1, Type_2, Type_1) -> std::string { return "(Type_1, Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_1, Type_2, Type_2) -> std::string { return "(Type_1, Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_1, Type_1) -> std::string { return "(Type_1, Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_1, Type_2) -> std::string { return "(Type_1, Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_1, Type_2, Type_2, Type_1) -> std::string { return "(Type_1, Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_1, Type_2, Type_2, Type_2) -> std::string { return "(Type_1, Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_1, Type_1) -> std::string { return "(Type_1, Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_1, Type_2) -> std::string { return "(Type_1, Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_1, Type_2, Type_1) -> std::string { return "(Type_1, Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_1, Type_2, Type_2) -> std::string { return "(Type_1, Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_1, Type_1) -> std::string { return "(Type_1, Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_1, Type_2) -> std::string { return "(Type_1, Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_1, Type_2, Type_2, Type_2, Type_1) -> std::string { return "(Type_1, Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_1, Type_2, Type_2, Type_2, Type_2) -> std::string { return "(Type_1, Type_2, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_1, Type_1) -> std::string { return "(Type_2, Type_1, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_1, Type_2) -> std::string { return "(Type_2, Type_1, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_1, Type_2, Type_1) -> std::string { return "(Type_2, Type_1, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_1, Type_2, Type_2) -> std::string { return "(Type_2, Type_1, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_1, Type_1) -> std::string { return "(Type_2, Type_1, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_1, Type_2) -> std::string { return "(Type_2, Type_1, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_1, Type_2, Type_2, Type_1) -> std::string { return "(Type_2, Type_1, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_1, Type_2, Type_2, Type_2) -> std::string { return "(Type_2, Type_1, Type_2, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_1, Type_1) -> std::string { return "(Type_2, Type_2, Type_1, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_1, Type_2) -> std::string { return "(Type_2, Type_2, Type_1, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_1, Type_2, Type_1) -> std::string { return "(Type_2, Type_2, Type_1, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_1, Type_2, Type_2) -> std::string { return "(Type_2, Type_2, Type_1, Type_2, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_1, Type_1) -> std::string { return "(Type_2, Type_2, Type_2, Type_1, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_1, Type_2) -> std::string { return "(Type_2, Type_2, Type_2, Type_1, Type_2)"; },
        [](Type_2, Type_2, Type_2, Type_2, Type_1) -> std::string { return "(Type_2, Type_2, Type_2, Type_2, Type_1)"; },
        [](Type_2, Type_2, Type_2, Type_2, Type_2) -> std::string { return "(Type_2, Type_2, Type_2, Type_2, Type_2)"; },
    };

    for (auto _ : state) {
        std::size_t r1 = sample_uniform_random(0, 1);
        std::size_t r2 = sample_uniform_random(0, 1);
        std::size_t r3 = sample_uniform_random(0, 1);
        std::size_t r4 = sample_uniform_random(0, 1);
        std::size_t r5 = sample_uniform_random(0, 1);
        auto result = std::visit(visitor, arr[r1], arr[r2], arr[r3], arr[r4], arr[r5]);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_std_visit_arity_5);

BENCHMARK_MAIN();