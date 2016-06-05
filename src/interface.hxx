namespace om636
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // ctor
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class ... V>
    ctor<T, U, V ...>::ctor()
    : m_impl( new builder_impl< product_type, map_type, arguments_type, 0 >() )
    {}

    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class ... V>
    template<typename ... W>
    ctor<T, U, V ...>::ctor( arguments_type args, W ... vars)
    : m_impl( new builder_impl< product_type, map_type, arguments_type, sizeof ... ( W ) >( args, { vars ... } ) )
    {
        static_assert( sizeof ... ( V ) >= sizeof ... ( W ), "expecting less or equal variables than arguments" );
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class ... V>
    auto ctor<T, U, V ...>::build(const map_type & m) -> product_type
    {
        return m_impl->build(m);
    }
}   // om636