#include <iostream>
#include "increase.h"

int main()
{
    const int start{20};
    int result{increase(start)};

    std::cout << "Result: " << result << '\n';
    return 0;
}