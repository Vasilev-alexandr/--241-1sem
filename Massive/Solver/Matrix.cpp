#include "Matrix.h"
#include "Generator.h"
#include <sstream>

namespace miit::algebra
{
    template <typename T>
    Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

    template <typename T>
    Matrix<T>::Matrix(int rows, int cols, Generator<T>& generator) : rows(rows), cols(cols), data(rows, std::vector<T>(cols))
    {
        fill(generator);
    }

    template <typename T>
    void Matrix<T>::fill(Generator<T>& generator)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    template <typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
    {
        other.rows = 0;
        other.cols = 0;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = std::move(other.data);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    template <typename T>
    std::vector<T>& Matrix<T>::operator[](int index)
    {
        return data[index];
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](int index) const
    {
        return data[index];
    }

    template <typename T>
    int Matrix<T>::getRows() const
    {
        return rows;
    }

    template <typename T>
    int Matrix<T>::getCols() const
    {
        return cols;
    }

    template <typename T>
    std::string Matrix<T>::toString() const
    {
        std::ostringstream oss;
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                oss << elem << " ";
            }
            oss << std::endl;
        }
        return oss.str();
    }
}