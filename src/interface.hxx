namespace om636
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // ctor
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U>
    ctor<T, U>::ctor()
    : m_impl( new builder_impl< product_type, map_type, std::tuple<>, 0 >() )
    {}
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U>
    template<class V, class ... W>
    ctor<T, U>::ctor( V args, W ... vars)
    : m_impl( new builder_impl< product_type, map_type, V, sizeof ... (W) >( args, std::array< std::string, sizeof ... (W) >{ vars ... } ) )
    {
        static_assert( std::tuple_size< V >::value >= sizeof ... ( W ), "expecting less or equal variables than arguments" );
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U>
    auto ctor<T, U>::build(const map_type & m) -> product_type
    {
        return m_impl->build(m);
    }
}   // om636