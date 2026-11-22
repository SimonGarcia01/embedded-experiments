#include <sstream>
#include <string>
#include <iostream>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};
};


std::string formatReading(int sensorId, double voltage) {
    std::ostringstream out;
    out << "Sensor " << sensorId << ": " << voltage << " V";
    return out.str();
}

std::string formatReading(const SensorReading& reading) {
    std::ostringstream out;
    out << "Sensor " << reading.sensorId << ": " << reading.voltage << " V";
    return out.str();
};

int main() {
    SensorReading reading{7, 3.25};
    std::string label = formatReading(reading);
    std::cout << label;
};