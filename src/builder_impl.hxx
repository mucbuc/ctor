namespace om636
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // builder_impl<T, U, V, N>
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V, int N >
    template<int ... M>
    auto builder_impl<T, U, V, N>::create(const arguments_type & args, ctor_private::seq<M...>) const -> product_type
    {
        return product_type{ std::get<M>(args) ... };
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V, int N >
    builder_impl<T, U, V, N>::builder_impl( arguments_type args, array_type vars )
    : m_args(args)
    , m_vars(vars)
    {}

    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V, int N >
    auto builder_impl<T, U, V, N>::build(const map_type & m) const -> product_type
    {
        using namespace std;
        using namespace om636;
        
        arguments_type args( m_args );
        apply_variables( args, m_vars, m, int_to_type< N >() );
        return create( args, typename ctor_private::gens< tuple_size<arguments_type>::value >::type() );
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V, int N >
    auto builder_impl<T, U, V, N>::clone() const -> base_type *
    {
        return new builder_impl( * this );
    }
    
}   // om636