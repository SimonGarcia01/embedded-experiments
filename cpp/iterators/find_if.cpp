#include <algorithm>
#include <iostream>
#include <vector>

//This is the predicate for the find_if function
bool isOutOfRange(int number){
    if(number < 10 || number > 50){
        return true;
    }

    return false;
}

int main() {
    std::vector<int> readings {10, 25, 50, 5, 60};
    std::vector<int>::const_iterator begin = readings.cbegin();
    std::vector<int>::const_iterator end = readings.cend();

    auto found = std::find_if(begin, end, isOutOfRange);

    if(found != end){
        std::cout << *found << '\n';
    }
    else {
        std::cout << "Not found" << '\n';
    }
}