#ifndef IOP_LIB_SENSORS_COOLER_ARDUINO_HPP
#define IOP_LIB_SENSORS_COOLER_ARDUINO_HPP

#include <cooler.hpp>

namespace relay {
auto Cooler::actIfNeeded() noexcept -> bool {
    if (this->dht.get().measureTemperature() > this->max) {
        this->relay.set(iop_hal::io::Data::HIGH);
    } else {
        this->relay.set(iop_hal::io::Data::LOW);
    }
    return true;
}
}

#endif