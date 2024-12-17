#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    template <typename T>
    class RandomGenerator : public Generator<T>
    {
    private:
        std::uniform_int_distribution<T> distribution;
        std::mt19937 generator;

    public:
        RandomGenerator(const T min, const T max);
        T generate() override;
    };
}