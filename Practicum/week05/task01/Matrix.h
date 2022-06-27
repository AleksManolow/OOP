#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int mSize;
    int** mMatrix;

    int** allocateMemory(size_t size) const;
    void copy(const Matrix&);
    void copyValue(int**);
    void deleteMemory();
public:
    Matrix();
    Matrix(size_t, int**);
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    ~Matrix();

    void printMatreix()const;

    int** getMatrix() const;
    size_t getSize() const;

    int getAt(size_t i, size_t j) const;
    Matrix add(const Matrix&) const;
};
#endif