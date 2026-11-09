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

    std::vector<int> ids(readings.size());

    std::vector<SensorReading>::const_iterator begin = readings.cbegin();
    std::vector<SensorReading>::const_iterator end = readings.cend();
    
    std::vector<int>::iterator idsBegin = ids.begin();

    std::transform(begin, end, idsBegin,[] (const SensorReading& reading) {
        return reading.sensorId;
    });

    for(int id : ids) {
        std::cout << id << '\n';
    };

};