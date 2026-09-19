#include "poly_array.h"
#include "utils.h"


// Simple case of 2 variants
namespace qc{
    /*
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
    */
}

template<typename... Callables>
struct Visitor : Callables...{
    using Callables::operator()...;
};

// Codegen - https://godbolt.org/z/8jTGTxezn
namespace qc::flat_array{
    template <typename Visitor, typename... Variants>
	decltype(auto) visit(Visitor &&visitor, Variants &&...vs) {
        constexpr std::size_t vtable_size = (std::variant_size_v<std::remove_cvref_t<Variants>> * ...);

        // Each entry in the vtable should have the shape [](Visitor visitor, Variants... vs){}
        using result_t = decltype(std::forward<Visitor>(visitor)(std::get<0>(std::forward<Variants>(vs))...));
        using cases_t = result_t(*)(Visitor&&, Variants&&...);

        static constexpr auto vtable{
            []<size_t... Indices>(std::index_sequence<Indices...>){
                constexpr std::array<std::size_t, sizeof...(Variants)> dimensions = { std::variant_size_v<std::remove_cvref_t<Variants>>... };
                constexpr std::size_t vtable_size = (std::variant_size_v<std::remove_cvref_t<Variants>> * ...);
                return std::array<cases_t, vtable_size>{
                    [](Visitor&& vis, Variants&&... vs) -> result_t{
                        constexpr auto multi_idx = qc::tools::from_1d_index<std::variant_size_v<std::remove_cvref_t<Variants>>...>(Indices);
                        return [&]<size_t... Is>(std::index_sequence<Is...>){
                            //return vis((static_cast<std::variant_alternative_t<multi_idx[Is], std::remove_cvref_t<Variants>>>(std::get<multi_idx[Is]>(vs)))...);
                            return std::forward<Visitor>(vis)(*(std::get_if<multi_idx[Is]>(&std::forward<Variants>(vs)))...);
                        }(std::make_index_sequence<sizeof...(Variants)>());
                    }...
                };
            }(std::make_index_sequence<vtable_size>())
        };

        auto i = qc::tools::to_1d_index<std::variant_size_v<std::remove_cvref_t<Variants>>...>(vs.index()...);
        return vtable[i](std::forward<Visitor>(visitor), std::forward<Variants>(vs)... );
	}
}

// Godbolt: https://godbolt.org/z/4nKqehq11
namespace qc{
    // An implementation of visit using multi-dimensional arrays
    namespace multidim_array{
        template<typename Visitor, typename... Vs>
        constexpr decltype(auto) visit(Visitor&& visitor, Vs&&... vs){
            auto func_table = qc::make_func_poly_array<Visitor, Vs...>();
            auto func = func_table.at(vs.index()...);
            return func(std::forward<Visitor>(visitor), std::forward<Vs>(vs)...);
        }
    }
}

namespace qc{
    namespace mdspan_impl{
        template<typename Visitor, typename... Vs>
        constexpr decltype(auto) visit(Visitor&& visitor, Vs&&... vs){
            
        }
    }
}
