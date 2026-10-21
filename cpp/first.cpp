#include <iostream>

void change(int* p)
{
    *p = 30;
    p = nullptr;
}

int main()
{
    int number{10};
    int* pointer{&number};

    change(pointer);

    std::cout << "number: " << number << '\n';
    std::cout << "pointer still points to number: "
              << (pointer == &number) << '\n';

    return 0;
}