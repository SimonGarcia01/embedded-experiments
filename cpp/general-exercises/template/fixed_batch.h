#include <concepts>
#include <cstddef>
#include <array>

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