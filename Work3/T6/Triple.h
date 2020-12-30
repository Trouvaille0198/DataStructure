#ifndef TRIPLE_H
#define TRIPLE_H
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
struct Triple
{
    int _row, _col;
    DataType _value;

    Triple(){};
    Triple(int row, int col, DataType value) : _row(row), _col(col), _value(value){};
};

#endif