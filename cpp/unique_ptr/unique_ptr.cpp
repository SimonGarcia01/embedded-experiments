#include <iostream>
#include <memory>
#include <vector>
#include <utility>

class MeasurementBatch {

private:
    std::vector<int> readings;

public:
    bool add(int value) {
        if (readings.size() >= 5) {
            return false;
        }

        readings.push_back(value);
        return true;
    }

    void showReadings() const {
        std::cout << "Readings: ";
        for (const auto& reading : readings) {
            std::cout << reading << " ";
        }
        std::cout << '\n';
    }
};

std::unique_ptr<MeasurementBatch> makeBatch() {
    std::unique_ptr<MeasurementBatch> batch = std::make_unique<MeasurementBatch>();
    batch->add(10);
    batch->add(20);
    return batch;
}

int main() {
    std::unique_ptr<MeasurementBatch> batch = makeBatch();
    batch->showReadings();
}