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

std::optional<SensorReading> strictParseReading(const std::string& text) {
    std::istringstream input{text};
    
    int id{0};
    char separator{};
    double voltage{0.0};

    //Normal parse of int Id, separator and double voltage check
    if (!(input >> id >> separator >> voltage)) {
        return std::nullopt;
    }

    //Check if the separator is a comma
    if (separator != ',') {
        return std::nullopt;
    }

    //Check if there is any trailing junk after the voltage value
    //This consumes a single whitespace character
    input >> std::ws;

    //Check if the stream is at the end of the file, if not return nullopt
    if (!input.eof()) {
        return std::nullopt;
    }

    return SensorReading{id, voltage};
};

int main() {
    SensorReading nonStrictReading;
    SensorReading strictReading;

    std::string text{"7,3.10junk"};

    std::optional<SensorReading> result = parseReading(text);
    std::optional<SensorReading> strictResult = strictParseReading(text);

    if(result) {
        nonStrictReading = *result;
    }

    if(strictResult) {
        strictReading = *strictResult;
    }

    std::cout << "Non Strict: Sensor " << nonStrictReading.sensorId << ": " << nonStrictReading.voltage << " V" << '\n';
    std::cout << "Strict: Sensor " << strictReading.sensorId << ": " << strictReading.voltage << " V" << '\n';
};