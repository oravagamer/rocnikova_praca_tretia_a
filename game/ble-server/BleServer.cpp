#include "BleServer.hpp"

BleServer::BleServer() {
    if (!SimpleBLE::Adapter::bluetooth_enabled()) {
        throw SimpleBLE::Exception::BaseException("Bluetooth is not enabled" );
    }

    auto adapters = SimpleBLE::Adapter::get_adapters();
    if (adapters.empty()) {
        throw SimpleBLE::Exception::BaseException("No Bluetooth adapters found");
    }

    // Use the first adapter
    auto adapter = adapters[0];

    // Do something with the adapter
    std::cout << "Adapter identifier: " << adapter.identifier() << std::endl;
    std::cout << "Adapter address: " << adapter.address() << std::endl;
}
