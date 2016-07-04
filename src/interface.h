#ifndef BUILDER_WRAPPER_H_323LK23KLK33403KWWQ
#define BUILDER_WRAPPER_H_323LK23KLK33403KWWQ

#include <memory>
#include <tuple>

#include <lib/ctor/src/builder_impl.h>

namespace om636
{
    
    //ctor<T, U>::defaultedWith( tuple<int, double>(0, 0) ).overridenBy( "radius" );
    
    
    template<class T, class U, class V>
    struct partial_ctor : ctor< T, U >
    {
        typedef ctor< T, U > base_type;
        using typename base_type::product_type;
        using typename base_type::map_type;
        typedef V arguments_type;
    
        partial_ctor(arguments_type args)
        : base_type( args )
        , m_args( args )
        {}
        
        template<class ... W>
        ctor<T, U> overridenBy(W ... vars)
        {
            return ctor<T, U>( m_args, vars ... );
        }
        
    private:
        arguments_type m_args;
    };
    
    template<class T, class U >
    struct ctor
    {
        typedef T product_type;
        typedef U map_type;

        template<class ... V>
        static partial_ctor<T, U, std::tuple<V ... > > defaultedWith(V ... args)
        {
            typedef std::tuple<V ... > tuple_type;
            return partial_ctor<T, U, tuple_type >{ tuple_type{ args ... } };
        }
        
        ctor();
        
        template<class V, class ... W>
        ctor( V, W ... );
        
        product_type build(const map_type &);
    
    private:        
        std::unique_ptr< builder<product_type, map_type> > m_impl;
    };
}   // om636

#include "interface.hxx"

#endif // BUILDER_WRAPPER_H_323LK23KLK33403KWWQ