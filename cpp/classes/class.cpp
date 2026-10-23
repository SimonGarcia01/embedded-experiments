#include <iostream>
#include <vector>

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

    std::size_t size() const {
        return readings.size();
    }

    void clear() {
        readings.clear();
    }
};


int main() {
    MeasurementBatch batch;

    for (int i = 0; i < 7; ++i) {
        if (batch.add(i * 10)) {
            std::cout << "Added reading: " << i * 10 << '\n';
        } else {
            std::cout << "Failed to add reading: " << i * 10 << " (batch full)\n";
        }
    }

    std::cout << "Total readings in batch: " << batch.size() << '\n';

    batch.clear();
    std::cout << "Batch cleared. Total readings now: " << batch.size() << '\n';

    return 0;
}