#include "ExerciseVirtual.h"
#include <iostream>

namespace miit::matrix::exercises
{
    ExerciseVirtual::ExerciseVirtual(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator> generator,
        std::ostream& out)
        : out(out)
    {
        matrix = std::make_unique<miit::algebra::Matrix>(rows, columns, *generator);
    }

    void ExerciseVirtual::Run()
    {
        out << "=== " << title() << " ===" << std::endl;

        out << "»сходна¤ матрица:" << std::endl;
        out << *matrix << std::endl;

        out << "–езультат выполнени¤ Task 1:" << std::endl;
        Task1();

        out << "–езультат выполнени¤ Task 2:" << std::endl;
        Task2();
    }
}