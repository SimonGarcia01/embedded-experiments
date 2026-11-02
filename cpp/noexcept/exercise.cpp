#include <iostream>
#include <vector>

struct Item {

    //Default constructor
    Item() = default;

    //Copy constructor
    Item(const Item&) {
        std::cout << "Copy\n";
    }

    //Move constructor
    Item(Item&&) noexcept {
        std::cout << "Move\n";
    }
};

int main() {
    std::vector<Item> items(2);
    items.reserve(items.capacity() + 1);
}