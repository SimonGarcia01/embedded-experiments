#include <iostream>
#include <vector>
#include <span>
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

    std::size_t size() const {
        return readings.size();
    }

    void clear() {
        readings.clear();
    }

    std::span<const int> data() const {
        return readings;
    }
};

//Added a helper function to consume the batch and print its size
void consume(MeasurementBatch batch){
    std::cout << "Parameter size: " << batch.size() << '\n';
}

int main() {
    MeasurementBatch source;
    source.add(10);
    source.add(20);

    consume(source);
    std::cout << "After copy: " << source.size() << '\n';

    consume(std::move(source));
    std::cout << "After move: " << source.size() << '\n';

    consume(source);
    std::cout << "After copy after it was moved: " << source.size() << '\n';

    source.clear();
    source.add(7);
    std::cout << "After reuse: " << source.size() << '\n';
}