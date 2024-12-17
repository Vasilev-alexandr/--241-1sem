#include "RandomGenerator.h"

namespace miit::algebra
{
    template <typename T>
    RandomGenerator<T>::RandomGenerator(const T min, const T max)
    {
        this->generator = std::mt19937(std::random_device{}());
        this->distribution = std::uniform_int_distribution<T>(min, max);
    }

    template <typename T>
    T RandomGenerator<T>::generate()
    {
        return this->distribution(this->generator);
    }
}