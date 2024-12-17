#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    template <typename T>
    class IStreamGenerator : public Generator<T>
    {
    private:
        std::istream& in;

    public:
        IStreamGenerator(std::istream& in = std::cin);
        T generate() override;
    };
}