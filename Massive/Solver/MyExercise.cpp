#include "MyExercise.h"
#include <iostream>

std::string MyExercise::title() const noexcept
{
    return "My Exercise";
}

void MyExercise::Task1()
{
    out << "Выполнение задачи 1:" << std::endl;

    for (int i = 0; i < this->matrix->getRows(); ++i)
    {
        int max_elem = (*this->matrix)[i][0];
        for (int j = 1; j < this->matrix->getCols(); ++j)
        {
            if ((*this->matrix)[i][j] > max_elem)
            {
                max_elem = (*this->matrix)[i][j];
            }
        }

        for (int j = 0; j < this->matrix->getCols(); ++j)
        {
            if ((*this->matrix)[i][j] == max_elem)
            {
                (*this->matrix)[i][j] = -max_elem;
            }
        }
    }

    out << *this->matrix << std::endl;
}

void MyExercise::Task2()
{
    out << "Выполнение задачи 2:" << std::endl;

    for (int j = 0; j < this->matrix->getCols(); ++j)
    {
        int max_elem = (*this->matrix)[0][j];
        for (int i = 1; i < this->matrix->getRows(); ++i)
        {
            if ((*this->matrix)[i][j] > max_elem)
            {
                max_elem = (*this->matrix)[i][j];
            }
        }

        for (int i = 0; i < this->matrix->getRows(); ++i)
        {
            for (int k = 0; k < this->matrix->getCols(); ++k)
            {
                if ((*this->matrix)[i][k] == max_elem)
                {
                    (*this->matrix)[i].insert((*this->matrix)[i].begin() + k + 1, 0);
                    k++;
                }
            }
        }
    }

    out << *this->matrix << std::endl;
}