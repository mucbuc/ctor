#ifndef CTOR_FWD_H_INCLUDE_GUARD_PPDMEO2MFE
#define CTOR_FWD_H_INCLUDE_GUARD_PPDMEO2MFE

#include <map> 
#include <string>

namespace om636
{   
 	// builder.h
    template<typename, typename>
    struct builder;

    // builder_impl.h
	template<class, class, class, int >
	struct builder_impl;

    // interface.h
    template< class, class = std::map< std::string, std::string > >
    class ctor;
}



#endif 