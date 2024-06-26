#pragma once

namespace siga::util {

template<typename F, typename... Args>
[[nodiscard]] constexpr auto bind_front_unwrap(F &&f, Args &&...args)
    noexcept(is_nothrow_decay_copyable_v<F> && (... && is_nothrow_decay_copyable_v<Args>))
{
    return std::bind_front(unwrap_args(std::forward<F>(f)), std::forward<Args>(args)...);
}

template<typename F, typename... Args>
[[nodiscard]] constexpr auto bind_back_unwrap(F &&f, Args &&...args)
    noexcept(is_nothrow_decay_copyable_v<F> && (... && is_nothrow_decay_copyable_v<Args>))
{
    return std::bind_back(unwrap_args(std::forward<F>(f)), std::forward<Args>(args)...);
}

// ------------------------------------------------------------------------------------------------

template<typename T>
[[nodiscard]] constexpr auto equal_to(T &&value)
    noexcept(noexcept(bind_front_unwrap(std::equal_to(), std::forward<T>(value))))
{
    return bind_front_unwrap(std::equal_to(), std::forward<T>(value));
}

// ------------------------------------------------------------------------------------------------

template<typename T>
[[nodiscard]] constexpr auto not_equal_to(T &&value)
    noexcept(noexcept(bind_front_unwrap(std::not_equal_to(), std::forward<T>(value))))
{
    return bind_front_unwrap(std::not_equal_to(), std::forward<T>(value));
}

// ------------------------------------------------------------------------------------------------

// TODO: there's a (compiler?) bug where it won't compile if a container is wrapped in `std::ref`
template<typename Container>
[[nodiscard]] constexpr auto index_in(Container &&container)
    noexcept(noexcept(bind_front_unwrap(subscript(), std::forward<Container>(container))))
{
    return bind_front_unwrap(subscript(), std::forward<Container>(container));
}

// ------------------------------------------------------------------------------------------------

template<typename Idx>
[[nodiscard]] constexpr auto index_with(Idx &&idx)
    noexcept(noexcept(bind_back_unwrap(subscript(), std::forward<Idx>(idx))))
{
    return bind_back_unwrap(subscript(), std::forward<Idx>(idx));
}

} // namespace siga::util
