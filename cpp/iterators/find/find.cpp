#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> readings{10, 20, 30, 40, 50};

    std::vector<int>::iterator last = readings.begin() + 3;
    auto found = std::find(readings.begin(), last, 40);

    if (found != last) {
        std::cout << "Found: " << *found << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

    last = readings.end();
    found = std::find(readings.begin(), last, 40);
    
    if(found != last){
        std::cout << *found << '\n';
    }
    else {
        std::cout << "Not Found" << '\n';
    }
}