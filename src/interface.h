#ifndef BUILDER_WRAPPER_H_323LK23KLK33403KWWQ
#define BUILDER_WRAPPER_H_323LK23KLK33403KWWQ

#include <memory>
#include <tuple>

#include <lib/ctor/src/builder_impl.h>

namespace om636
{
    template<class T, class U >
    struct ctor
    {
        typedef T product_type;
        typedef U map_type;

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