#ifndef APPLY_VARIABLES_H_039829832223230LKJDSF
#define APPLY_VARIABLES_H_039829832223230LKJDSF

#include <sstream>
#include <tuple>

#include <lib/static/interface.h>

namespace om636 {
template <class T, class U, class V, int N>
void apply_variables(T&, const U& args, const V& map, int_to_type<N>);

template <class T, class U, class V>
void apply_variables(T&, const U& args, const V& map, int_to_type<0>);
}

#include "apply_variables.hxx"

#endif // APPLY_VARIABLES_H_039829832223230LKJDSF