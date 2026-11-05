#include <iostream>
#include <vector>
#include <memory>
#include <utility>

struct Sensor {
    int id;

    explicit Sensor(int initialId) : id{initialId} {
        std::cout << "Created " << id << '\n';
    }

    ~Sensor() {
        std::cout << "Destroyed " << id << '\n';
    }

    void print() const {
        std::cout << "Sensor " << id << '\n';
    }
};

std::unique_ptr<Sensor> takeLast(std::vector<std::unique_ptr<Sensor>>& sensors) {
    if (sensors.empty()) {
        return nullptr;
    }

    auto extracted = std::move(sensors.back());
    sensors.pop_back();

    return extracted;
};

int main() {
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<Sensor>(7));
    sensors.push_back(std::make_unique<Sensor>(8));

    std::unique_ptr<Sensor> firstCall = takeLast(sensors);
    std::unique_ptr<Sensor> secondCall = takeLast(sensors);
    std::unique_ptr<Sensor> thirdCall = takeLast(sensors);

    if(firstCall) {
        firstCall->print();
    } 
    else {
        std::cout << "No Sensor" << '\n';
    }

    if(secondCall) {
        secondCall->print();
    } 
    else {
        std::cout << "No Sensor" << '\n';
    }

    if(thirdCall) {
        thirdCall->print();
    } 
    else {
        std::cout << "No Sensor" << '\n';
    }

    std::cout << "Final Vector Size: " << sensors.size() << '\n';
};