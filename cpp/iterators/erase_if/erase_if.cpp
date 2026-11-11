#include <iostream>
#include <vector>

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

    auto removed = std::erase_if(readings, [] (const SensorReading& reading) {
        return reading.voltage >= 3.0;
    });

    for(SensorReading reading : readings){
        reading.print();
    };

    std::cout << removed << '\n';
};
