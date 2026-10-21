#include <iostream>
#include <array>
#include <span>

int sum(std::span<const int> values) {

    int total{0};

    for(int value : values) {
        total += value;
    }

    return total;
}

int main() {
    std::array<int, 3> readings{4, 8, 12};
    std::cout << sum(readings) << '\n'; // Expected: 24
}