#include <iostream>
#include <optional>

struct SensorReading{
    int sensorId{0};
    double voltage{0.0};

    void print() const {
        std::cout << "Sensor ID: " << sensorId << '\n';
        std::cout << "Voltage: " << voltage << '\n';
    }
};

//This is a concept that checks if a type T has a const print() method
template <typename T>
concept HasConstPrint = requires(const T& item) {
    item.print();
};

//Original generic printItem function that is tested against the HasConstPrint concept
//This function takes a const reference to an item of type T and calls its print() method
//This forces the compiler to check if the type T has a const print() method at compile time
template <HasConstPrint T>
void printItem(const T& item) {
    item.print();
}

//This is an unconstrained version of the printItem
//It doesnt require the type T to have a const print() method
//It lets those that do have the const print method to be printed, and those that dont have it to be ignored
template <typename T>
void printIfSupported(const T& item) {
    if constexpr (HasConstPrint<T>) {
        item.print();
    } 
    else {
        std::cout << "No print method available\n";
    }
};

int main() {
    //This creates a SensorReading object
    SensorReading reading{7, 2.75};
    printIfSupported(reading);

    //This creates an int object
    printIfSupported(5);
};