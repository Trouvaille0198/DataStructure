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
    TriSparseMatrix<DataType> operator+(const TriSparseMatrix<DataType> &copy);

    int GetRows() const { return _rows; }
    int GetCols() const { return _cols; }
    int GetNum() const { return _num; }
    void SetElem(int row, int col, const DataType &v);
    void Display();
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
//三种情况：非零变零，零变非零，非零变非零
{
    if (v == 0) //若设置非零值为零
    {
        int i;
        for (i = 0; i < _num; i++) //找到要设零的非零值
        {
            if (_data[i]._row == row && _data[i]._col == col)
            {
                //_data[i] = 0;
                break;
            }
        }
        if (i != _num) //说明确实设置了非零数为零
        {
            for (int j = i; j < _num - 1; j++)
            {
                _data[j] = _data[j + 1];
            }
            _num--; //非零值个数-1
        }
    }
    else
    {
        Triple<DataType> e(row, col, v);
        int i;
        for (i = 0; i < _num; i++)
        {
            if (_data[i]._row == row && _data[i]._col == col) //修改非零值
            {
                _data[i] = e;
                break;
            }
        }
        if (i == _num) //设置零值为非零值
            _data[_num++] = e;
    }
}

template <class DataType>
void TriSparseMatrix<DataType>::Display()
{
    for (int i = 0; i < _num - 1; i++)
    {
        cout << "(" << _data[i]._row << ", " << _data[i]._col << ", " << _data[i]._value << ")";
    }
    cout << "(" << _data[_num - 1]._row << ", " << _data[_num - 1]._col
         << ", " << _data[_num - 1]._value << ")" << endl;
}

template <class DataType>
DataType TriSparseMatrix<DataType>::GetElem(int row, int col)
{
    DataType result = 0;
    for (int i = 0; i < _num; i++)
    {
        if (_data[i]._row == row && _data[i]._col == col)
        {
            result = _data[i]._value;
            break;
        }
    }
    return result;
}

template <class DataType>
TriSparseMatrix<DataType> &TriSparseMatrix<DataType>::operator=(const TriSparseMatrix<DataType> &copy)
{
    if (&copy != this)
    {
        if (_data)
            delete[] _data;
        _rows = copy._rows;
        _cols = copy._cols;
        _maxLen = copy._maxLen;
        _num = copy._num;
        _data = new Triple<DataType>[_maxLen];
        for (int i = 0; i < _num; i++)
        {
            _data[i] = copy._data[i];
        }
    }
    return *this;
}

template <class DataType>
TriSparseMatrix<DataType> TriSparseMatrix<DataType>::operator+(const TriSparseMatrix<DataType> &e)
{
    TriSparseMatrix<DataType> result(_rows, _cols, DEFAULT_SIZE);
    //result._num = 0;
    if (_rows != e._rows || _cols != e._cols)
    {
        cout << "两矩阵行列数不等，无法进行加法运算！" << endl;
        exit(1);
    }
    int i = 0;                     //控制左值，即this
    int j = 0;                     //控制右值，即e
    DataType value;                //存放临时的非零值值
    while (i < _num && j < e._num) //直到一个矩阵的非零元素被遍历完
    {
        if (_data[i]._row == e._data[j]._row) //行号相等时
        {
            if (_data[i]._col == e._data[j]._col) //行列号都相等时
            {
                value = _data[i]._value + e._data[j]._value;
                if (value != 0)
                {
                    result.SetElem(_data[i]._row, _data[i]._col, value);
                }
                i++;
                j++;
                //continue;
            }
            else if (_data[i]._col > e._data[j]._col) //行号相等，左值列号>右值列号
            {
                result.SetElem(e._data[j]._row, e._data[j]._col, e._data[j]._value); //将右值（即列较小值）添加到新矩阵中
                j++;
            }
            else //行号相等，左值列号<右值列号
            {
                result.SetElem(_data[i]._row, _data[i]._col, _data[i]._value); //将左值（即列较小值）添加到新矩阵中
                i++;
            }
        }
        else if (_data[i]._row > e._data[j]._row) //左值行号>右值行号时
        {
            result.SetElem(e._data[j]._row, e._data[j]._col, e._data[j]._value); //将右值（即行较小值）添加到新矩阵中
            j++;
        }
        else //左值行号<右值行号时
        {
            result.SetElem(_data[i]._row, _data[i]._col, _data[i]._value); //将左值（即行较小值）添加到新矩阵中
            i++;
        }
    }
    while (i < _num) //若左值中有剩余元素
    {
        result.SetElem(_data[i]._row, _data[i]._col, _data[i]._value);
        i++;
    }
    while (j < e._num) //若右值中有剩余元素
    {
        result.SetElem(e._data[j]._row, e._data[j]._col, e._data[j]._value);
        j++;
    }
    return result;
}

#endif