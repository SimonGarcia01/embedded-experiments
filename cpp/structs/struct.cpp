#include <iostream>

struct SensorReading {
    int sensorId;
    double voltage;
};

int main() {

    SensorReading first{3, 2.75};
    SensorReading second = first;

    std::cout << "First sensor ID: " << first.sensorId << '\n';
    std::cout << "First sensor voltage: " << first.voltage << '\n';
    std::cout << "Second sensor ID: " << second.sensorId << '\n';
    std::cout << "Second sensor voltage: " << second.voltage << '\n';

    second.voltage = 1.5;
    std::cout << "First sensor voltage after change: " << first.voltage << '\n';
    std::cout << "Second sensor voltage after change: " << second.voltage << '\n';

    return 0;
}