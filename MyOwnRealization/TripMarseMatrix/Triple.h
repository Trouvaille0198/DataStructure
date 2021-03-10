#ifndef TRIPLE_H
#define TRIPLE_H
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Triple
{
    int _row, _col;
    T _value;

    Triple(){};
    Triple(int row, int col, T value) : _row(row), _col(col), _value(value){};
};

#endif