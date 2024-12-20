#pragma once
#include "..//Solver/Generator.h"
#include "..//Solver/Matrix.h"
#include <iostream>
#include <memory>

namespace miit::matrix::exercises
{
    class ExerciseVirtual
    {
    protected:
        std::unique_ptr<miit::algebra::Matrix> matrix;
        std::ostream& out;

        virtual std::string title() const noexcept = 0;
        virtual void Task1() = 0;
        virtual void Task2() = 0;

    public:
        explicit ExerciseVirtual(
            const int rows,
            const int columns,
            std::unique_ptr<miit::algebra::Generator> generator,
            std::ostream& out = std::cout);

        virtual ~ExerciseVirtual() = 0 {};

        void Run();
    };
}