#include <iostream>
#include <utility>
#include <memory>

struct Sensor {
    int id;

    explicit Sensor(int initialId) : id{initialId} {}

    void print() const {
        std::cout << "Sensor " << id << '\n';
    }
};

int main() {

    std::unique_ptr<Sensor> sensor = std::make_unique<Sensor>(7);

    Sensor* raw = sensor.get();

    raw -> print();

    std::unique_ptr<Sensor> newSensor = std::move(sensor);

    raw -> print();
};