#include"Matrix.h"

int** Matrix::allocateMemory(size_t size) const
{
    int** matrix = new int* [size]
    for (int i = 0; i < size; i++)
    {
        matrix = new int[size];
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
void Matrix::copyValue(int** rhs)
{
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            mMatrix[i][j] = rhs[i][j];
        }
    }
}
void Matrix::copy(const Matrix& rhs)
{
    mSize = rhs.mSize
    mMatrix = allocateMemory(mSize);
    copyValue(mMatrix);
}
void Matrix::deleteMemory()
{
    for (int i = 0; i < mSize; i++)
    {
        delete[] mMatrix[i];
    }
    delete[] mMatrix;
}

Matrix::Matrix()
{
    mSize = 3;
    mMatrix = nullptr;
}
Matrix::Matrix(size_t _mSize, int** _mMatrix)
{
    mSize = _mSize;
    mMatrix = allocateMemory(mSize);
    copyValue(_mMatrix);
}
Matrix::Matrix(const Matrix& rhs)
{
    copy(rhs);
}
Matrix::Matrix& operator=(const Matrix& rhs)
{
    if(this != &rhs)
    {
        deleteMemory();
        copy(rhs);
    }
    return *this;
}
Matrix::~Matrix()
{
    deleteMemory();
}

void Matrix::printMatreix()const
{
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
        {
            std::cout << mMatrix[i][j] << ' ';
        }  
        std::cout << std::endl;
    }
}
int** Matrix::getMatrix() const
{
    return mMatrix;
}
size_t Matrix::getSize() const
{
    return mSize;
}
int Matrix::getAt(size_t i, size_t j) const
{
    if(i >= mSize || j >= mSize || i < 0 || j < 0) 
    {
		throw "Invalid index!";
	}

    return mMatrix[i][j];
}
Matrix* Matrix::add(const Matrix& rhs) const 
{
    if (this->mSize != rhs.mSize) 
    {
		throw "Invalid matrix addition!";
	}

    size_t sumSize = rhs.mSize;
	int** sumMatrix =  allocateMemory(sumSize);
	for(size_t i = 0; i < sumSize; i++) {
		for(size_t j = 0; j < sumSize; j++) {
			sumMatrix[i][j] = mMatrix[i][j] + rhs.mMatrix[i][j];
		}
	}
    return new Matrix(sumSize, sumMatrix);
}