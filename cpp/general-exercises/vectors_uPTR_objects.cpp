#include <iostream>
#include <vector>
#include <memory>

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

int main() {
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<Sensor>(7));

    Sensor* rawPtr = sensors[0].get();

    sensors.reserve(sensors.capacity() + 1);

    rawPtr->print();

    sensors.clear();

}