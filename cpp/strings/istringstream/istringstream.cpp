#include <optional>
#include <string>
#include <sstream>
#include <iostream>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};
};

std::optional<SensorReading> parseReading(const std::string& text) {
    //Input borrows the caller string and doesn't copy it
    //the string gets copied into the istringstream buffer = parse data from the string
    std::istringstream input{text};

    int id{0};
    char separator{};
    double voltage{0.0};

    if (!(input >> id >> separator >> voltage)) {
        return std::nullopt;
    }

    if (separator != ',') {
        return std::nullopt;
    }

    //SensorReading{id, voltage} contains copies of the parsed numbers. 
    //Returning it constructs a populated optional. It doesn’t return references to local variables.
    return SensorReading{id, voltage};
};

int main() {
    SensorReading reading;

    std::string text{"7,3.10junk"};

    std::optional<SensorReading> result = parseReading(text);

    if(result) {
        reading = *result;
    }

    std::cout << "Sensor " << reading.sensorId << ": " << reading.voltage << " V";
};