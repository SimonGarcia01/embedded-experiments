#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int low{10};
    int high{50};

    auto countOutsideRange = [low, high] (int reading) {
        return reading < low || reading > high;
    };

    std::vector<int> readings{10, 25, 50, 5, 60};

    std::vector<int>::iterator begin = readings.begin();
    std::vector<int>::iterator end = readings.end();

    auto found = std::count_if(begin, end, countOutsideRange);
    
    std::cout << found << '\n';

}