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

//Here we make it a generic function that can take any input stream and output stream
void displayReadings(std::istream& input, std::ostream& output) {
    std::string line;

    while (std::getline(input, line)) {
        if (auto reading = strictParseReading(line)) {
            output << formatReading(*reading) << '\n';
        }
        else {
            output << "Invalid reading\n";
        }
    }
}

int main() {
    std::ifstream file{"cpp/streams/files/readings.txt"};

    if (!file) {
        std::cout << "Could not open readings.txt\n";
        return 1;
    }

    displayReadings(file, std::cout);

    //we have to refresh the file stream to read it again, so we close and reopen it
    //If we don't do that, the file stream will be at the end of the file and we won't be able to read it again
    file.close();

    file.open("cpp/streams/files/readings.txt");

    //the same can be achieved by cleaing the stream state and seeking the beginning of the file
    //file.clear();
    //file.seekg(0, std::ios::beg);

    std::ofstream report{"cpp/streams/files/report.txt"};

    if (!report) {
        std::cout << "Could not open report.txt\n";
        return 1;
    }

    displayReadings(file, report);
}