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
        int rows;
        int cols;

    public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, Generator<T>& generator);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix() = default;

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        std::vector<T>& operator[](int index);
        const std::vector<T>& operator[](int index) const;

        int getRows() const;
        int getCols() const;

        void fill(Generator<T>& generator);
        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
        {
            for (int i = 0; i < matrix.rows; ++i)
            {
                for (int j = 0; j < matrix.cols; ++j)
                {
                    os << matrix.data[i][j] << " ";
                }
                os << std::endl;
            }
            return os;
        }
    };
}