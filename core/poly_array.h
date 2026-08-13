#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <array>
#include <functional>
#include <variant>

namespace dev{
    /**
     * @brief A light n-dimensional array.
     * 
     */
    template<typename T, std::size_t Size>
    struct poly_array{
        T m_buffer[Size] = {};

        template<typename... Ts>
        poly_array(Ts... values)
        {
            using result_t = std::common_type_t<std::remove_cv_t<Ts>...>;
            static_assert(std::is_same_v<T, result_t>);
            m_buffer = { {values...} };
        }

        constexpr T& operator[](std::size_t idx){
            return m_buffer[idx];
        }
 
        template<typename... Indices>
        decltype(auto) constexpr at(std::size_t index, Indices... indices){
            return at(m_buffer[index], indices...);
        }

        template<typename U, typename... Indices>
        decltype(auto) constexpr at(U elements, std::size_t index, Indices... indices){
            return at(elements[index], indices...);
        }
    };

    template<size_t... Indices>
    struct dispatcher{
        static constexpr auto dispatch = []<typename Func, typename... Vs>(Func f, Vs... vs){
            using return_type_t = decltype(f(std::get<0>(vs)...));
            if constexpr(std::is_same_v<return_type_t, void>){
                std::invoke(f, std::get<Indices>(vs)...);
            }else{
                return std::invoke(f, std::get<Indices>(vs)...);
            }
        };
    };

    template<typename Func, typename... Vs, size_t... Indices>
    constexpr auto make_dispatch(std::index_sequence<Indices...>){
        return dispatcher<Indices...>::template dispatch<Func, Vs...>;
    }

    template<typename Func, typename V, typename... Vs, size_t... Is, size_t... Js, typename... Seqs>
    constexpr auto make_func_poly_array_impl(std::index_sequence<Is...>, std::index_sequence<Js...>, Seqs... seqs){
        // return poly_array( /* What should go here*/ )
    }

    template<typename Func, typename... Vs>
    constexpr auto make_func_poly_array(){
            return make_func_poly_array_impl<Func, Vs...>(std::index_sequence<>(), std::make_index_sequence<std::variant_size_v<Vs>>()...);
    }
}