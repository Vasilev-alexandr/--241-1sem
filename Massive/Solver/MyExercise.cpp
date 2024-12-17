#include "MyExercise.h"
#include <iostream>

template <typename T>
std::string MyExercise<T>::title() const noexcept
{
    return "My Exercise";
}

template <typename T>
void MyExercise<T>::Task1()
{
    out << "Выполнение задачи 1:" << std::endl;

    for (int i = 0; i < this->matrix->getRows(); ++i)
    {
        T max_elem = (*this->matrix)[i][0];
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

template <typename T>
void MyExercise<T>::Task2()
{
    out << "Выполнение задачи 2:" << std::endl;

    for (int j = 0; j < this->matrix->getCols(); ++j)
    {
        T max_elem = (*this->matrix)[0][j];
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