#ifndef BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN
#define BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN

#include <tuple>
#include <sstream>

namespace om636
{

    template<class T, class U> 
    struct basic_builder 
    {
        typedef T product_type;
        typedef U map_type;
        typedef typename map_type::key_type string_type; 
        
        basic_builder(const map_type &); 

        product_type * build() const;
        
        template<class V>
        product_type * build(string_type) const;
        
        template<class V>
        product_type * build(string_type, string_type) const;
        
        template<class V>
        product_type * build(string_type, string_type, string_type) const; 
        
        template<class V>
        product_type * build(string_type, string_type, string_type, string_type) const; 
        
        template<class V>
        product_type * build(string_type, string_type, string_type, string_type, string_type) const;    
    
    private:
        const map_type & m_map;
    };

}

#include "builder.hxx"

#endif // BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN