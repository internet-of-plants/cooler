#ifndef IOP_LIB_SENSORS_COOLER_HPP
#define IOP_LIB_SENSORS_COOLER_HPP

#include <relay.hpp>
#include <dht.hpp>

namespace relay {
class Cooler {
    relay::Relay relay;
    std::reference_wrapper<dht::Dht> dht;
    float max;
public:
    // TODO: should it be std::shared_ptr?
    Cooler(const iop_hal::PinRaw pin, const std::reference_wrapper<dht::Dht> dht, const float max) noexcept: relay(pin), dht(dht), max(max) {}
    Cooler(relay::Relay relay, const std::reference_wrapper<dht::Dht> dht, const float max) noexcept: relay(std::move(relay)), dht(dht), max(max)  {}
    
    auto begin() const noexcept -> void {
        this->relay.begin();
    }

    auto reset() noexcept -> void {
        this->relay.set(iop_hal::io::Data::LOW);
    }

    auto actIfNeeded() noexcept -> bool;
};
}

#endif