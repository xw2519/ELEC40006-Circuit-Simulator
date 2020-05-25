#include "vsrc_resolver.hpp"

vsource* src_resolver (std::vector<std::string> store)
{
    // ID component 'v' has already been removed
    // Deterimine if 'SINE' is mentioned in input
    if (store[3] == "SINE" || store[3] == "sine")
    {
        // Extract SINE parameters
        return new vsource(store[0], GetNode(store[1]), GetNode(store[2]), "SINE", converter(store[4]), converter(store[5]), converter(store[6]));
    }
    else if (store.size() == 3)
    {
        // Treat as DC source
        return new vsource(store[0], GetNode(store[1]), GetNode(store[2]), "DC", converter(store[3]), 0, 0);
    }
    else{std::cerr << "Unsupported voltage source type." << std::endl; }
};