#ifndef ENUM_CLASS_ALLOW_FLAGS_HPP
#define ENUM_CLASS_ALLOW_FLAGS_HPP

#ifdef __AVR__
#include "../avr_helpers/type_traits.h"
#else
#include <type_traits>
#endif

namespace flags {

template <class E, class Enabler = void> struct is_flags
: public std::false_type {};

} // namespace flags

#define ALLOW_FLAGS_FOR_ENUM(name) \
namespace flags { \
template <> struct is_flags< name > : std::true_type {}; \
}

#endif // ENUM_CLASS_ALLOW_FLAGS_HPP
