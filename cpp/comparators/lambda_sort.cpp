#include <iostream>
#include <vector>
#include <algorithm>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};

    void print() const
    {
        std::cout << "Sensor ID: " << sensorId << '\n';
        std::cout << "Voltage: " << voltage << '\n';
    }
};

int main() {
    std::vector<SensorReading> readings{
        {7, 2.75},
        {3, 3.10},
        {2, 2.75}
    };

    std::vector<SensorReading>::iterator begin = readings.begin();
    std::vector<SensorReading>::iterator end = readings.end();

    auto comparatorVoltageThenId = [] (const SensorReading& a, const SensorReading& b) {
        if (a.voltage > b.voltage) {
            return true;
        }

        return a.voltage == b.voltage && a.sensorId < b.sensorId;
    };


    std::sort(begin, end, comparatorVoltageThenId);

    for(SensorReading reading : readings) {
        reading.print();
    };

};