#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};
};

std::string formatReading(const SensorReading& reading) {
    std::ostringstream out;
    //This is to format the string to hold 2 decimal places
    out << std::fixed << std::setprecision(2);

    //This actually formats the string with the values
    out << "Sensor " << reading.sensorId << ": " << reading.voltage << " V";
    return out.str();
};

int main() {
    SensorReading reading{7, 3.1};
    std::string label = formatReading(reading);
    std::cout << label;
};