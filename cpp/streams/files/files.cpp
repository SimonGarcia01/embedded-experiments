#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};
};

std::string formatReading(const SensorReading& reading) {
    std::ostringstream out;
    out << "Sensor " << reading.sensorId << ": " << reading.voltage << " V";
    return out.str();
};

std::optional<SensorReading> strictParseReading(const std::string& text) {
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

    input >> std::ws;

    if (!input.eof()) {
        return std::nullopt;
    }

    return SensorReading{id, voltage};
};

void displayReadings(std::istream& input) {
    std::string line;

    while (std::getline(input, line)) {
        if (auto reading = strictParseReading(line)) {
            std::cout << formatReading(*reading) << '\n';
        }
        else {
            std::cout << "Invalid reading\n";
        }
    }
}

int main() {
    std::ifstream file{"cpp/streams/files/readings.txt"};

    if (!file) {
        std::cout << "Could not open readings.txt\n";
        return 1;
    }

    displayReadings(file);
}