#pragma once
#include "Generator.h"
#include <vector>
#include <iostream>
#include <string>

namespace miit::algebra
{
    template <typename T>
    class Matrix
    {
    private:
        std::vector<std::vector<T>> data;
        size_t rows;
        size_t cols;

    public:
        Matrix(size_t rows, size_t cols);
        Matrix(size_t rows, size_t cols, Generator<T>& generator);
       
        std::vector<T>& operator[](size_t index);
        const std::vector<T>& operator[](size_t index) const;

        size_t getRows() const;
        size_t getCols() const;

        void fill(Generator<T>& generator);
        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
        {
            for (size_t i = 0; i < matrix.rows; ++i)
            {
                for (size_t j = 0; j < matrix.cols; ++j)
                {
                    os << matrix.data[i][j] << " ";
                }
                os << std::endl;
            }
            return os;
        }
    };
}