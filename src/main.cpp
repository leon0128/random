#include <iostream>

#include "random.hpp"

int main(int argc, char **argv)
{
    RANDOM::Random<> random;

    for(int i = 0; i < 10; i++)
    {
        std::cout << random() << std::endl;
        std::cout << random(100) << std::endl;
        std::cout << random(1000, 10000) << std::endl;
        std::cout << random.random() << std::endl;
        std::cout << random.random<short>() << std::endl;
        std::cout << random.floating() << std::endl;
        std::cout << random.floating<float>() << std::endl;
    }

    return 0;
}