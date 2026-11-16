#include <array>
#include <concepts>
#include <cstddef>
#include <iostream>

template <typename T>
concept NumericReading = std::integral<T> || std::floating_point<T>;

template <NumericReading T, std::size_t N>
struct FixedBatch {
    // Ensures that the batch size is greater than zero at compile time
    static_assert(N > 0, "FixedBatch needs at least one reading");

    // Member variable to hold readings
    std::array<T, N> readings{};

    constexpr double average() const {

        double sum{0.0};
        
        for (const T& reading : readings) {
            sum += static_cast<double>(reading);
        }

        return sum / static_cast<double>(N);
    }
};

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