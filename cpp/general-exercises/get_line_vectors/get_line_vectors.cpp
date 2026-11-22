#include <vector>
#include <string>
#include <sstream>
#include <iostream>

std::string printVector(const std::vector<std::string>& vector) {
    std::ostringstream out;
    for (const std::string& str : vector) {
        out << '[' <<str << "]\n";
    }
    return out.str();
};

std::vector<std::string> readLines(std::istream& input){
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    return lines;
};

int main() {
    std::istringstream input{"First\n\nSecond\n"};
    std::vector<std::string> lines = readLines(input);
    std::cout << printVector(lines);
};