#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <string>
#include <vector>
#include <stdexcept>

template<typename T>

class Matrix {
    public:

        // Constructors and destructor:

        Matrix(size_t rows, size_t cols, const std::string& name) : rows(rows), cols(cols), name(name), data(rows*cols) {}
        Matrix(size_t rows, size_t cols) : Matrix(rows, cols, "New matrix") {}
        Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols), name(other.name), data(other.data) {}
        Matrix() : Matrix(1, 1, "New matrix") {}
        ~Matrix() {}

        // Operators:

        T* operator[](size_t index) {
            return data.data() + index * cols;
        }

        const T* operator[](size_t index) const {
            return data.data() + index * cols;
        }

        Matrix<T>& operator=(const Matrix<T>& other) {
            if(this != &other) {
                rows = other.rows;
                cols = other.cols;
                name = other.name;
                data = other.data;
            }
            return *this;
        }

        Matrix<T> operator+(const Matrix<T>& other) const {
            if(rows != other.rows || cols != other.cols) {
                throw std::invalid_argument("Matrix sizes do not match!");
            }

            Matrix<T> result(*this);
            for(size_t i = 0; i < rows; ++i) {
                for(size_t j = 0; j < cols; ++j) {
                    result[i][j] += other[i][j];
                }
            }
            return result;
        }

        Matrix<T> operator-(const Matrix<T>& other) const;
        Matrix<T> operator*(const Matrix<T>& other) const;

        // Main methods

        void fillIdentity();
        void fillHilbert();
        T detLU() const;
        T detRecursive() const;
        Matrix<T> inverse() const;
        void print() const;
        friend Matrix<T> operator*(const Matrix<T>& other, T scalar);
        friend Matrix<T> operator*(T scalar, const Matrix<T>& other);
        Matrix<T> transpose() const;


        // Getters

        size_t getRows() const { return rows; }
        size_t getCols() const { return cols; }
        std::string getName() const {return name;}
        
        // Validation

        bool isSquare() const { return rows == cols; }

    private:

        size_t rows, cols;
        std::string name;
        std::vector<T> data;
        Matrix<T> getMinor(size_t p, size_t q) const;
};

#endif