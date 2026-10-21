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

void addTwo(std::span<int> values) {
    for (int& value : values)
    {
        value += 2;
    }
}

int main() {
    std::array<int, 3> readings{4, 8, 12};
    addTwo(readings);
    std::cout << sum(readings) << '\n'; // Expected: 24
}