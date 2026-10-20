#include <iostream>

int increase(int value)
{
    return value + 1;
}

int main()
{
    const int start{20};
    int result{increase(start)};

    std::cout << "Result: " << result << '\n';
    return 0;
}