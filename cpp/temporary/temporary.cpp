#include <iostream>

struct Trace
{
    Trace()
    {
        std::cout << "Constructed\n";
    }

    ~Trace()
    {
        std::cout << "Destroyed\n";
    }
};

void inspect(const Trace&)
{
    std::cout << "Inside inspect\n";
}

int main()
{
    std::cout << "A\n";
    inspect(Trace{});
    std::cout << "B\n";

    const Trace& kept{Trace{}};
    std::cout << "C\n";
}