#include "IStreamGenerator.h"

namespace miit::algebra
{
    template <typename T>
    IStreamGenerator<T>::IStreamGenerator(std::istream& in) : in{ in } {}

    template <typename T>
    T IStreamGenerator<T>::generate()
    {
        T value;
        this->in >> value;
        return value;
    }
}