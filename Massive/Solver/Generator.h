#pragma once

namespace miit::algebra
{
    template <typename T>
    class Generator
    {
    public:
        virtual ~Generator() = 0 {};
        virtual T generate() = 0;
    };
}