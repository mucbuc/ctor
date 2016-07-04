namespace om636
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // ctor
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V>
    ctor<T, U, V>::ctor()
    : m_impl( new builder_impl< product_type, map_type, arguments_type, 0 >() )
    {
        static_assert( std::tuple_size< V >::value > 0, "expecting less or equal variables than arguments" );
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V>
    template<class ... W>
    ctor<T, U, V>::ctor( arguments_type args, W ... vars)
    : m_impl( new builder_impl< product_type, map_type, arguments_type, sizeof ... (W) >( args, std::array< std::string, sizeof ... (W) >{ vars ... } ) )
    {
        static_assert( std::tuple_size< V >::value >= sizeof ... ( W ), "expecting less or equal variables than arguments" );
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V>
    auto ctor<T, U, V>::build(const map_type & m) -> product_type
    {
        return m_impl->build(m);
    }
}   // om636