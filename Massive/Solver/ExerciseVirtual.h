#pragma once
#include "..//Solver/Generator.h"
#include "..//Solver/Matrix.h"
#include <iostream>
#include <memory>

namespace miit::matrix::exercises
{
    template <typename T>
    class ExerciseVirtual
    {
    protected:
        std::unique_ptr<miit::algebra::Matrix<T>> matrix;
        std::ostream& out;

        virtual std::string title() const noexcept = 0;
        virtual void Task1() = 0;
        virtual void Task2() = 0;

    public:
        explicit ExerciseVirtual(
            const int rows,
            const int columns,
            std::unique_ptr<miit::algebra::Generator<T>> generator,
            std::ostream& out = std::cout);

        virtual ~ExerciseVirtual();

        void Run();
    };
}