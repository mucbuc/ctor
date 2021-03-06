namespace om636 {

/////////////////////////////////////////////////////////////////////////////////////////////
// ctor<T, U>::ctor_with_args<V>
/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
template <class V>
ctor<T, U>::ctor_with_args<V>::ctor_with_args(arguments_type args)
    : ctor(args)
    , m_args(args)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
template <class V>
template <class... W>
ctor<T, U> ctor<T, U>::ctor_with_args<V>::overridenBy(W... vars)
{
    return ctor<T, U>(m_args, vars...);
}

/////////////////////////////////////////////////////////////////////////////////////////////
// ctor
/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
ctor<T, U>::ctor(const ctor& other)
    : m_impl(other.m_impl ? other.m_impl->clone() : nullptr)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
template <class V, class... W>
ctor<T, U>::ctor(V args, W... vars)
    : m_impl(new builder_impl<product_type, map_type, V, sizeof...(W)>(args, std::array<std::string, sizeof...(W)>{ vars... }))
{
    static_assert(std::tuple_size<V>::value >= sizeof...(W), "expecting less or equal variables than arguments");
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
auto ctor<T, U>::build(const map_type& m) const -> product_type
{
    return m_impl->build(m);
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
template <class... V>
auto ctor<T, U>::defaultedWith(V... args) -> ctor_with_args<std::tuple<V...>>
{
    typedef std::tuple<V...> tuple_type;
    return ctor_with_args<tuple_type>{ tuple_type{ args... } };
}

} // om636