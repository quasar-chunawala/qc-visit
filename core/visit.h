#include "poly_array.h"
#include <type_traits>
#include <array>
#include <initializer_list>
#include <memory>
#include <utility>
#include <variant>
#include <numeric>
#include <iostream>
#include <print>
#include <format>

namespace qc::tools{
    /*template<std::size_t... Dimensions>
    constexpr auto build_coeffs_array(){
        constexpr std::array<std::size_t, sizeof...(Dimensions)> dimensions { Dimensions... };
        constexpr std::size_t coeffs_size = sizeof...(Dimensions);
        std::array<std::size_t, coeffs_size> coeffs = {};
        
        for(std::size_t i{0}; i < coeffs_size; ++i)
            coeffs[i] = 1;

        for(std::size_t i{0}; i < coeffs_size - 1; ++i){
            // In step i, we need to populate all coeffs[j], j <= i
            for(std::size_t j{0}; j <= i; ++j){
                coeffs[j] *= dimensions[i+1];
            }
        }
        return coeffs;
    }*/
    template<std::size_t... Dimensions>
    constexpr auto build_coeffs_array(){
        constexpr std::array<std::size_t, sizeof...(Dimensions)> dimensions { Dimensions... };
        constexpr std::size_t coeffs_size = sizeof...(Dimensions);
        std::array<std::size_t, coeffs_size> coeffs = {};
        
        coeffs[coeffs_size - 1] = 1;

        for(int i{coeffs_size - 2}; i >= 0; i--){
            coeffs[i] = dimensions[i + 1] * coeffs[i + 1];
        }
        return coeffs;
    }
    /*
    coeff[0] = v1size * ... * v[n-1] size
    coeff[1] = v2size * .... *v[n-1] size
    ...
    coeff[n-2] = v[n-1] size
    coeff[n-1] = 1
    */
    template<std::size_t... Dimensions>
    std::size_t constexpr to_1d_index(auto... indices){
        constexpr std::array<std::size_t, sizeof...(Dimensions)> dimensions { Dimensions... };
        std::size_t coeffs_size = sizeof...(Dimensions);
        auto coeffs = build_coeffs_array<Dimensions...>();
        //std::println("{}", coeffs);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
        const std::array<size_t, sizeof...(indices)> indices_arr { indices... };
        //std::println("{}", indices_arr); 
        return std::inner_product(coeffs.begin(), coeffs.end(), indices_arr.begin(), 0); 
    }

    /*
    Suppose we have the dimensions <3, 5, 2> and the coordinates (1, 3, 1).
    (1, 3, 1) maps to the linear index 17. 
    */

    template<size_t N>
    constexpr auto build_coords_array(std::array<size_t,N> coeffs, size_t& initState){ 
        size_t state = initState;
        std::array<size_t, N> coords{};
        for(size_t i{0}; i < N; ++i){
            coords[i] = static_cast<size_t>(state / coeffs[i]);
            state -= coords[i] * coeffs[i];
        }
        return coords;
    }

    template<size_t... Dimensions>
    decltype(auto) constexpr from_1d_index(std::size_t n){
        constexpr std::size_t coords_arr_size = sizeof...(Dimensions);
        static constexpr auto coeffs = build_coeffs_array<Dimensions...>();
        std::array<size_t, coords_arr_size> coords = build_coords_array(coeffs, n);
        return coords;
    }
}

// Simple case of 2 variants
namespace qc{

    namespace example{

        struct Dummy{};
        template<typename T>
        using Wrapper = std::conditional_t<std::is_void_v<T>,Dummy,T>;


        template<typename Visitor, typename Variant0, typename Variant1>
        decltype(auto) visit(Visitor&& visitor, Variant0 v0, Variant1 v1){
            constexpr std::array<std::size_t, 2> dimensions = { std::variant_size_v<Variant0>, std::variant_size_v<Variant1> };
            constexpr std::size_t vtable_size = (std::variant_size_v<Variant0> * std::variant_size_v<Variant1>);
            using cases_t = std::string(*)(Visitor, Variant0, Variant1);
            static constexpr auto vtable {
                []<size_t... Indices>(std::index_sequence<Indices...>){
                    return std::array<cases_t,4>{
                        [](Visitor vis, Variant0 v0, Variant1 v1){ 
                            constexpr auto multi_idx = qc::tools::from_1d_index<2,2>(Indices);
                            return vis(std::get<multi_idx[0]>(v0), std::get<multi_idx[1]>(v1));
                    }... };
                    
                }(std::make_index_sequence<vtable_size>())
            };

            return vtable[qc::tools::to_1d_index<2,2>(v0.index(), v1.index())](visitor, v0, v1);
        }
    };
}

template<typename... Callables>
struct Visitor : Callables...{
    using Callables::operator()...;
};

namespace qc::flat_array{
    template <typename Visitor, typename... Variants>
	decltype(auto) visit(Visitor &&visitor, Variants &&...vs) {
        constexpr std::size_t vtable_size = (std::variant_size_v<std::remove_cvref_t<Variants>> * ...);

        // Each entry in the vtable should have the shape [](Visitor visitor, Variants... vs){}
        using result_t = decltype(visitor(std::get<0>(vs)...));
        using cases_t = result_t(*)(Visitor, Variants...);

        static constexpr auto vtable{
            []<size_t... Indices>(std::index_sequence<Indices...>){
                constexpr std::array<std::size_t, sizeof...(Variants)> dimensions = { std::variant_size_v<std::remove_cvref_t<Variants>>... };
                constexpr std::size_t vtable_size = (std::variant_size_v<std::remove_cvref_t<Variants>> * ...);
                return std::array<cases_t, vtable_size>{
                    [](Visitor vis, Variants... vs) -> result_t{
                        constexpr auto multi_idx = qc::tools::from_1d_index<std::variant_size_v<std::remove_cvref_t<Variants>>...>(Indices);
                        return [&]<size_t... Is>(std::index_sequence<Is...>){
                            return vis((static_cast<std::variant_alternative_t<multi_idx[Is], std::remove_cvref_t<Variants>>>(std::get<multi_idx[Is]>(vs)))...);
                        }(std::make_index_sequence<sizeof...(Variants)>());
                    }...
                };
            }(std::make_index_sequence<vtable_size>())
        };

        auto i = qc::tools::to_1d_index<std::variant_size_v<std::remove_cvref_t<Variants>>...>(vs.index()...);
        return vtable[i](visitor, vs... );
	}
}

// Godbolt: https://godbolt.org/z/4nKqehq11
namespace qc{
    // An implementation of visit using multi-dimensional arrays
    namespace multidim_array{
        template<typename Visitor, typename... Vs>
        constexpr auto visit(Visitor&& visitor, Vs&&... vs){
            auto func_table = qc::make_func_poly_array<Visitor, Vs...>();
            auto func = func_table.at(vs.index()...);
            using result_t = decltype(func(std::forward<Visitor>(visitor), std::forward<Vs>(vs)...));
            if constexpr(std::is_same_v<result_t, void>){
                func(std::forward<Visitor>(visitor), std::forward<Vs>(vs)...);
            }else{
                return func(std::forward<Visitor>(visitor), std::forward<Vs>(vs)...);
            }
        }
    }
}
