#include <vector>
#include <span>
#include <iostream>

int main() {
    std::vector<int> vector{4, 8, 12};
    vector.reserve(10);

    std::span<const int> span{vector};

    vector.push_back(20);

    std::cout << "Vector size: " << vector.size() << '\n';
    std::cout << "Span size: " << span.size() << '\n';

    span = std::span<const int>{vector};
    std::cout << "Span size after reassigning: " << span.size() << '\n';
}