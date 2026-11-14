#include <array>
#include <concepts>
#include <cstddef>

template <typename T>
concept NumericReading = std::integral<T> || std::floating_point<T>;

template <NumericReading T, std::size_t N>
struct FixedBatch
{
    static_assert(N > 0, "FixedBatch needs at least one reading");

    std::array<T, N> readings{};

    double average() const
    {
        // Your code here
    }
};