#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Deep copy test
    {
        Array<int> tmp = numbers;
        Array<int> test(numbers);
    }

    // Basic functionality test
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Exception tests
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access numbers[-2]: " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access numbers[MAX_VAL]: " << e.what() << '\n';
    }

    // Indexing test
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();

    // Empty array test
    Array<float> empty;
    try
    {
        empty[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access empty[0]: " << e.what() << '\n';
    }

    // Reading/writing test
    std::cout << "numbers[0]: " << numbers[0] << std::endl;
    numbers[0] = 42;
    std::cout << "numbers[0]: " << numbers[0] << std::endl;

    delete[] mirror;
    return 0;
}
