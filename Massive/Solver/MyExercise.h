#pragma once
#include "ExerciseVirtual.h"

template <typename T>
class MyExercise : public miit::matrix::exercises::ExerciseVirtual<T>
{
public:
    MyExercise(
        const int rows,
        const int columns,
        std::unique_ptr<miit::algebra::Generator<T>> generator,
        std::ostream& out = std::cout)
        : ExerciseVirtual<T>(rows, columns, std::move(generator), out) {}

protected:
    std::string title() const noexcept override;
    void Task1() override;
    void Task2() override;
};