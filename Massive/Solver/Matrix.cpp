#include "Matrix.h"
#include "Generator.h"
#include <sstream>

namespace miit::algebra
{
    template <typename T>
    Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

    template <typename T>
    Matrix<T>::Matrix(size_t rows, size_t cols, Generator<T>& generator) : rows(rows), cols(cols), data(rows, std::vector<T>(cols))
    {
        fill(generator);
    }

    template <typename T>
    void Matrix<T>::fill(Generator<T>& generator)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }
    
    template <typename T>
    std::vector<T>& Matrix<T>::operator[](size_t index)
    {
        return data[index];
    }

    template <typename T>
    const std::vector<T>& Matrix<T>::operator[](size_t index) const
    {
        return data[index];
    }

    template <typename T>
    size_t Matrix<T>::getRows() const
    {
        return rows;
    }

    template <typename T>
    size_t Matrix<T>::getCols() const
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