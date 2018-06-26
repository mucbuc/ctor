#ifndef BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN
#define BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN

#include <lib/ctor/src/ctor_fwd.h>

namespace om636 {
/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, typename U>
struct builder {
    typedef T product_type;
    typedef U map_type;

    virtual ~builder() = default;
    virtual product_type build(const map_type&) const = 0;
    virtual builder* clone() const = 0;
};
}

#endif // BUIDER_H_INCLUDE_GUARD_33983289389I8903LKN