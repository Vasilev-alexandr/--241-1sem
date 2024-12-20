#include "Matrix.h"
#include "Generator.h"
#include <sstream>

namespace miit::algebra
{
    Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    Matrix::Matrix(size_t rows, size_t cols, Generator& generator) : rows(rows), cols(cols), data(rows, std::vector<int>(cols))
    {
        fill(generator);
    }

    void Matrix::fill(Generator& generator)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }

    std::vector<int>& Matrix::operator[](size_t index)
    {
        return data[index];
    }

    const std::vector<int>& Matrix::operator[](size_t index) const
    {
        return data[index];
    }

    size_t Matrix::getRows() const
    {
        return rows;
    }

    size_t Matrix::getCols() const
    {
        return cols;
    }

    std::string Matrix::toString() const
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