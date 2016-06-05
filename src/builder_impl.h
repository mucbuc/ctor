#ifndef BUILDER_IMPL_32002PP2P2P2P121322
#define BUILDER_IMPL_32002PP2P2P2P121322

#include <tuple>

#include <lib/ctor/src/builder.h>
#include <lib/ctor/src/apply_variables.h>

namespace om636
{
    namespace ctor_private
    {
        /*
         reference: 
         Johannes Schaub
         http://stackoverflow.com/questions/7858817/unpacking-a-tuple-to-call-a-matching-function-pointer
         */
        template<int ...> struct seq {};
        template<int N, int ...S> struct gens : gens<N-1, N-1, S...> {};
        template<int ...S> struct gens<0, S...>{ typedef seq<S...> type; };
    }
    
    template<class T, class U, class V, int N >
	struct builder_impl : builder< T, U >
	{
	    typedef builder< T, U > base_type;
	    using typename base_type::product_type;
	    using typename base_type::map_type;
	    typedef std::array< std::string, N > array_type;
	    typedef V arguments_type;
	    
	    builder_impl( arguments_type, array_type );
	    
	    product_type build(const map_type & m) const override;
    
	private:
	
        template<int ... M>
        product_type create(const arguments_type &, ctor_private::seq<M ...>) const;
        
        arguments_type m_args;
	    array_type m_vars;
	};


	template<class T, class U, class V>
	struct builder_impl<T, U, V, 0> : builder< T, U >
	{
	    typedef builder< T, U > base_type;
	    using typename base_type::product_type;
	    using typename base_type::map_type;
	    typedef V arguments_type;
	    
	    builder_impl();
	    
	    product_type build(const map_type & m) const override;
	    
	private:
	    arguments_type m_args;
	};
}

#include "builder_impl.hxx"

#endif // BUILDER_IMPL_32002PP2P2P2P121322
