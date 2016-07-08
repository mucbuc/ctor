#ifndef BUILDER_WRAPPER_H_323LK23KLK33403KWWQ
#define BUILDER_WRAPPER_H_323LK23KLK33403KWWQ

#include <map>
#include <memory>
#include <string>
#include <tuple>

#include <lib/ctor/src/builder_impl.h>

namespace om636
{   
    template<class T, class U = std::map< std::string, std::string > >
    struct ctor
    {
        template<class V>
        struct partial_ctor : ctor
        {
            typedef V arguments_type;
        
            partial_ctor(arguments_type);
            
            template<class ... W>
            ctor<T, U> overridenBy(W ...);
            
        private:
            arguments_type m_args;
        };

    public:
        typedef T product_type;
        typedef U map_type;
     
        ctor(const ctor &);
        virtual ~ctor() = default;

        product_type build(const map_type & = map_type{} ) const;

        template<class ... V>
        static partial_ctor<std::tuple<V ... > > defaultedWith(V ...);
        
    private:        

        ctor() = delete;
        ctor & operator=(const ctor &) = delete;
        ctor & operator=(ctor &&) = delete;
        
        template<class V, class ... W>
        ctor( V, W ... );
        
        std::unique_ptr< builder<product_type, map_type> > m_impl;
    };

}   // om636

#include "interface.hxx"

#endif // BUILDER_WRAPPER_H_323LK23KLK33403KWWQ