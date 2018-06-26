#ifndef BUILDER_WRAPPER_H_323LK23KLK33403KWWQ
#define BUILDER_WRAPPER_H_323LK23KLK33403KWWQ

#include <map>
#include <memory>
#include <string>
#include <tuple>

#include <lib/ctor/src/builder_impl.h>
#include <lib/ctor/src/ctor_fwd.h>

namespace om636 {
template <class T, class U>
class ctor {
    template <class V>
    struct ctor_with_args : ctor {
        typedef V arguments_type;

        ctor_with_args(arguments_type);
        ~ctor_with_args() = default;

        template <class... W>
        ctor overridenBy(W...);

    private:
        arguments_type m_args;
    };

    ctor() = delete;
    ctor& operator=(const ctor&) = delete;
    ctor& operator=(ctor&&) = delete;

    template <class V, class... W>
    ctor(V, W...);

public:
    typedef T product_type;
    typedef U map_type;

    ctor(const ctor&);
    ~ctor() = default;

    product_type build(const map_type& = map_type{}) const;

    template <class... V>
    static ctor_with_args<std::tuple<V...>> defaultedWith(V...);

private:
    std::unique_ptr<builder<product_type, map_type>> m_impl;
};

} // om636

#include "interface.hxx"

#endif // BUILDER_WRAPPER_H_323LK23KLK33403KWWQ