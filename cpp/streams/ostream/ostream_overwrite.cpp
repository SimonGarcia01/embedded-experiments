#include <iostream>
#include <optional>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};

    void print() const
    {
        std::cout << "Sensor ID: " << sensorId << '\n';
        std::cout << "Voltage: " << voltage << '\n';
    }
};

//This operation must be defined outside the struct
//The left hand operator is a stream object
//This is an overload of the << operator for the SensorReading struct
//The operator takes a reference to an ostream object and a const reference to a SensorReading object
//The operator returns a reference to the ostream object so that it can be used in a chain of output operations
//This allows us to use the << operator to output a SensorReading object to an ostream object (like std::cout)
std::ostream& operator<<(std::ostream& out, const SensorReading& reading) {

    out << "Sensor " << reading.sensorId << ": " << reading.voltage << " V";

    return out;
};

//Having the stream operator overloaded allows us to use the << operator to output a SensorReading object to an ostream object
//This makes the code be able to compile a call to std::cout << reading; where reading is a SensorReading object
template <typename T>
void printOptional(const std::optional<T>& value){
    if(value.has_value()){
        std::cout << *value << "\n";
    }
    else {
        std::cout << "No value\n";
    }
};

int main() {
    std::optional<SensorReading> emptyReading;
    std::optional<SensorReading> reading{SensorReading{7, 2.75}};

    printOptional(emptyReading);
    printOptional(reading);
}; 