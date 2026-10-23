#include <iostream>

struct SensorReading {
    int sensorId{0};
    double voltage{0.0};
};

void printReading(const SensorReading& reading) {
    std::cout << "Sensor ID: " << reading.sensorId << '\n';
    std::cout << "Voltage: " << reading.voltage << '\n';
}

int main() {

    SensorReading first{3, 2.75};
    SensorReading second = first;

    printReading(first);
    printReading(second);

    second.voltage = 1.5;
    std::cout << "First sensor voltage after change: " << first.voltage << '\n';
    std::cout << "Second sensor voltage after change: " << second.voltage << '\n';

    return 0;
}