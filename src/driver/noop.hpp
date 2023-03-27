#ifndef IOP_LIB_SENSORS_COOLER_NOOP_HPP
#define IOP_LIB_SENSORS_COOLER_NOOP_HPP

#include <cooler.hpp>

namespace relay {
auto Cooler::actIfNeeded() noexcept -> bool { return false; }
}

#endif