#include <iostream>
#include <vector>
#include <algorithm>

auto makeOddAndAbove(int limit){
    return [limit] (int reading) {
        return reading > limit && reading % 2 != 0;
    };
}

int main() {
    std::vector<int> readings{10, 25, 50, 5, 60};

    std::vector<int>::iterator begin = readings.begin();
    std::vector<int>::iterator end = readings.end();

    auto above10 = makeOddAndAbove(10);
    
    auto found = std::find_if(begin, end, above10);

    if(found != end){
        std::cout << *found << '\n';
    }
    else {
        std::cout << "Not Found" << '\n';
    }
}