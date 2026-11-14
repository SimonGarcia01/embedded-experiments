#include <cstddef>
#include <iostream>

//constexpr function that calculates the number of slots needed for a given number of sensors
//constexpr functions can be evaluated at compile time
constexpr std::size_t slotsFor(std::size_t sensorCount) {
    return sensorCount + 1;
}

int main() {
    //The static_assert checks the result at compile time
    //If the static_assert = false, the compilation will fail
    //In this case, this runs during compilation and slotsFor(4) can be evaluated since 4 is passed by value and is known at compile time
    static_assert(slotsFor(4) == 5);

    std::size_t count{};

    if (std::cin >> count) {

        //In this case, the function is evaluated at runtime since the value of count is not known at compile time
        const std::size_t total = slotsFor(count);

        std::cout << "Total slots: " << total << '\n';

    }
}