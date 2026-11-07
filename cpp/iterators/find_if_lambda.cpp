#include <iostream>
#include<vector>
#include <algorithm>

int main () {
    std::vector<int> readings{10, 25, 50, 5, 60};

    std::vector<int>::iterator begin = readings.begin();
    std::vector<int>::iterator end = readings.end();

    std::vector<int>::iterator found = std::find_if(
        begin, 
        end, 
        [] (int reading) {
            return reading > 10 && (reading % 2 != 0);
        });

    if(found != end){
        std::cout << *found << '\n';
    }
    else {
        std::cout << "Not Found" << '\n';
    }
}