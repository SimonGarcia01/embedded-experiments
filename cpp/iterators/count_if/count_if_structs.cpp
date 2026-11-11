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
        {3, 3.10},
        {7, 2.75},
        {2, 2.75}
    };

    std::vector<SensorReading> selected;

    std::vector<SensorReading>::const_iterator begin = readings.cbegin();
    std::vector<SensorReading>::const_iterator end = readings.cend();

    std::copy_if(begin, end, std::back_inserter(selected), [](const SensorReading& reading){
        return reading.voltage < 3.0;
    });

    for(SensorReading reading : selected) {
        reading.print();
    }


}