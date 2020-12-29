#ifndef TSM_H
#define TSM_H
#include "Triple.h"
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class TriSparseMatrix
//三元组顺序表实现
{
protected:
    static const int DEFAULT_SIZE = 100;
    Triple<DataType> *_data; //存储三元组的数组
    int _maxLen;             //非零元素最大个数
    int _rows, _cols, _num;  //行数、列数、非零元素个数
public:
    TriSparseMatrix(int rows = DEFAULT_SIZE, int cols = DEFAULT_SIZE, int maxLen = DEFAULT_SIZE);
    ~TriSparseMatrix();
    TriSparseMatrix(const TriSparseMatrix<DataType> &copy);
    TriSparseMatrix<DataType> &operator=(const TriSparseMatrix<DataType> &copy);

    int GetRows() const { return _rows; }
    int GetCols() const { return _cols; }
    int GetNum() const { return _num; }
    void SetElem(int row, int col, const DataType &v);
    DataType GetElem(int row, int col);

    void FastTranspose(const TriSparseMatrix<DataType> &source, const TriSparseMatrix<DataType> &dest);
};

template <class DataType>
TriSparseMatrix<DataType>::TriSparseMatrix(int rows, int cols, int maxLen) : _rows(rows), _cols(cols), _maxLen(maxLen)
//构造空稀疏矩阵
{
    _data = new Triple<DataType>[_maxLen];
    _num = 0;
}

template <class DataType>
TriSparseMatrix<DataType>::~TriSparseMatrix()
{
    if (_data)
        delete[] _data;
}

template <class DataType>
void TriSparseMatrix<DataType>::SetElem(int row, int col, const DataType &v)
{
    Triple<DataType> e(row, col, v);
    _data[_num++] = e;
}

template <class DataType>
DataType TriSparseMatrix<DataType>::GetElem(int row, int col)
{
    DataType result = 0;
    for (int i = 0; i < _maxLen; i++)
    {
        if (_data[i]._row == row && _data[i]._col == col)
        {
            result = _data[i]._value;
            break;
        }
    }
    return result;
}

#endif