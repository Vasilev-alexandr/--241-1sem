#include "ExerciseVirtual.h"
#include <iostream>

namespace miit::matrix::exercises
{
    template <typename T>
    ExerciseVirtual<T>::ExerciseVirtual(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator<T>> generator,
        std::ostream& out)
        : out(out)
    {
        matrix = std::make_unique<miit::algebra::Matrix<T>>(rows, columns, *generator);
    }

    template <typename T>
    ExerciseVirtual<T>::~ExerciseVirtual() = default;

    template <typename T>
    void ExerciseVirtual<T>::Run()
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