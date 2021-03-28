#ifndef TSM_H
#define TSM_H
#include "Triple.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class TriSparseMatrix
//三元组顺序表实现
{
protected:
    static const int DEFAULT_SIZE = 100;
    Triple<T> *_data;       //存储三元组的数组
    int _maxLen;            //非零元素最大个数
    int _rows, _cols, _num; //行数、列数、非零元素个数
public:
    TriSparseMatrix(int rows = DEFAULT_SIZE, int cols = DEFAULT_SIZE, int maxLen = DEFAULT_SIZE);
    ~TriSparseMatrix();
    TriSparseMatrix(const TriSparseMatrix<T> &copy);
    TriSparseMatrix<T> &operator=(const TriSparseMatrix<T> &copy);
    TriSparseMatrix<T> operator+(const TriSparseMatrix<T> &copy);

    int GetRows() const { return _rows; }
    int GetCols() const { return _cols; }
    int GetNum() const { return _num; }
    void SetElem(int row, int col, const T &v);
    T GetElem(int row, int col);
    void Display();

    void SimpleTranspose(TriSparseMatrix<T> &e); //简单转置
    void FastTranspose(TriSparseMatrix<T> &e);   //快速转置
};

template <class T>
TriSparseMatrix<T>::TriSparseMatrix(int rows, int cols, int maxLen) : _rows(rows), _cols(cols), _maxLen(maxLen)
//构造空稀疏矩阵
{
    _data = new Triple<T>[_maxLen];
    _num = 0;
}

template <class T>
TriSparseMatrix<T>::~TriSparseMatrix()
{
    if (_data)
        delete[] _data;
}

template <class T>
void TriSparseMatrix<T>::SetElem(int row, int col, const T &v)
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
        Triple<T> e(row, col, v);
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

template <class T>
void TriSparseMatrix<T>::Display()
{
    for (int i = 0; i < _num - 1; i++)
    {
        cout << "(" << _data[i]._row << ", " << _data[i]._col << ", " << _data[i]._value << ")";
    }
    cout << "(" << _data[_num - 1]._row << ", " << _data[_num - 1]._col
         << ", " << _data[_num - 1]._value << ")" << endl;
}

template <class T>
T TriSparseMatrix<T>::GetElem(int row, int col)
{
    T result = 0;
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

template <class T>
TriSparseMatrix<T>::TriSparseMatrix(const TriSparseMatrix<T> &copy)
{
    _rows = copy._rows;
    _cols = copy._cols;
    _maxLen = copy._maxLen;
    _num = copy._num;
    _data = new Triple<T>[_maxLen];
    for (int i = 0; i < _num; i++)
    {
        _data[i] = copy._data[i];
    }
}

template <class T>
TriSparseMatrix<T> &TriSparseMatrix<T>::operator=(const TriSparseMatrix<T> &copy)
{
    if (&copy != this)
    {
        if (_data)
            delete[] _data;
        _rows = copy._rows;
        _cols = copy._cols;
        _maxLen = copy._maxLen;
        _num = copy._num;
        _data = new Triple<T>[_maxLen];
        for (int i = 0; i < _num; i++)
        {
            _data[i] = copy._data[i];
        }
    }
    return *this;
}

template <class T>
TriSparseMatrix<T> TriSparseMatrix<T>::operator+(const TriSparseMatrix<T> &e)
{
    TriSparseMatrix<T> result(_rows, _cols, DEFAULT_SIZE);
    //result._num = 0;
    if (_rows != e._rows || _cols != e._cols)
    {
        cout << "两矩阵行列数不等，无法进行加法运算！" << endl;
        exit(1);
    }
    int i = 0;                     //控制左值，即this
    int j = 0;                     //控制右值，即e
    T value;                       //存放临时的非零值值
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

template <class T>
void TriSparseMatrix<T>::SimpleTranspose(TriSparseMatrix<T> &e)
//简单转置，时间复杂度O(_rows*_cols)
{
    e._rows = _rows;
    e._cols = _cols;
    e._num = 0;
    e._maxLen = _maxLen;
    delete[] e._data;
    e._data = new Triple<T>[_maxLen];
    for (int col = 0; col < _cols; col++) //对整个矩阵的列进行遍历
    {
        for (int i = 0; i < _num; i++) //对_data进行遍历
        {
            if (col == _data[i]._col) //若_data[i]中出现相应列，添加到e中
            {
                e.SetElem(_data[i]._col, _data[i]._row, _data[i]._value);
            }
        }
    }
    //*this = e;
}

template <class T>
void TriSparseMatrix<T>::FastTranspose(TriSparseMatrix<T> &e)
//快速转置，时间复杂度O(_num)
{
    e._rows = _rows;
    e._cols = _cols;
    e._num = _num;
    e._maxLen = _maxLen;
    delete[] e._data;
    e._data = new Triple<T>[_maxLen];

    int *DataNumInCol = new int[_cols]; //存放原矩阵每一列非零个数
    int *FirstDataIne = new int[_cols]; //存放原矩阵中每一列第一个非零元素在e中应有的索引位置
    for (int i = 0; i < _cols; i++)     //赋初值为0
        DataNumInCol[i] = 0;
    for (int i = 0; i < _num; i++) //记录每列的非零元素个数
        DataNumInCol[_data[i]._col]++;
    FirstDataIne[0] = 0;            //零列第一个非零元素必在索引为0的位置
    for (int i = 1; i < _cols; i++) //当前列第一个元素的索引位置=上一列的索引位置+上一列的元素个数
        FirstDataIne[i] = FirstDataIne[i - 1] + DataNumInCol[i - 1];
    for (int i = 0; i < _num; i++)
    {
        int j = FirstDataIne[_data[i]._col]; //j记录当前列的索引
        e._data[j]._row = _data[i]._col;
        e._data[j]._col = _data[i]._row;
        e._data[j]._value = _data[i]._value;
        FirstDataIne[_data[i]._col]++; //当前列的索引值+1
    }
    delete[] DataNumInCol;
    delete[] FirstDataIne;
    //*this = e;
}

#endif