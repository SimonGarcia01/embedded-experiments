#include <iostream>
#include <vector>
#include <optional>
#include <span>
#include <numeric>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};

    void print() const
    {
        std::cout << "Sensor ID: " << sensorId << '\n';
        std::cout << "Voltage: " << voltage << '\n';
    }
};

std::optional<double> averageVoltage(std::span<const SensorReading> readings) {

    if (readings.empty()) {
        return std::nullopt; // No average exists
    }

    std::span<const SensorReading>::iterator begin = readings.begin();
    std::span<const SensorReading>::iterator end = readings.end();

    // Compute and return the average

    auto calculateAverage = [] (double runningTotal, const SensorReading& reading) {
        return runningTotal + reading.voltage;
    };

    double total = std::accumulate(begin, end, 0.0, calculateAverage);

    return total / static_cast<double>(readings.size());
};

//This is the original version of the method specific to double
// void readOptionalDouble(std::optional<double> opDouble) {
//     if(opDouble){
//         std::cout << "Average: " << *opDouble << " V\n";
//     } 
//     else {
//         std::cout << "No readings\n";
//     }
// };

    //Here we implement the same method but a generic Template
    template <typename T>
    void printOptional(const std::optional<T>& value){
        if(value.has_value()){
            std::cout << *value << "\n";
        }
        else {
            std::cout << "No value\n";
        }
    }

    int main() {
        std::vector<SensorReading> readings{
            {3, 3.10},
            {7, 2.75},
            {2, 2.75}
        };

        std::vector<SensorReading> emptyReadings;

        std::optional<double> emptyAverage = averageVoltage(emptyReadings);

        std::optional<double> average = averageVoltage(readings);

        //Empty vector
        printOptional(emptyAverage);

        //Vector with values
        printOptional(average);

        //Random int value
        printOptional(std::optional<int>{0});
        
    };