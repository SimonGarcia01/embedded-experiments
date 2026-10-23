#include <iostream>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};

    void adjustVoltage(double adjustment)
    {
        voltage += adjustment;
    }

    void print() const
    {
        std::cout << "Sensor ID: " << sensorId << '\n';
        std::cout << "Voltage: " << voltage << '\n';
    }
};

int main() {

    SensorReading first{3, 2.75};
    SensorReading second = first;

    first.adjustVoltage(0.5);
    second.adjustVoltage(-0.25);

    first.print();
    second.print();

    const SensorReading third{5, 3.0};
    third.print();

    return 0;
}