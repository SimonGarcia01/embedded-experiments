#include <iostream>
#include "fixed_batch.h"

int main() {
    FixedBatch<int, 3> raw{{1, 2, 2}};
    FixedBatch<double, 2> volts{{2.75, 3.25}};

    std::cout << "Raw average: " << raw.average() << '\n';
    std::cout << "Volts average: " << volts.average() << '\n';
    
    raw.readings[0] = 4;
    std::cout << "Raw average: " << raw.average() << '\n';

    //Separate test with constexpr average so everything happens in compile time
    constexpr FixedBatch<int, 3> known{{1, 2, 3}};
    static_assert(known.average() == 2.0);

};