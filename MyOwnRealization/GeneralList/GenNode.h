#ifndef GENNODE_H
#define GENNODE_H
#include <bits/stdc++.h>
#include "GenList.h"
using namespace std;

template <class DataType>
class GenNode
{
private:
    GenNode *tlink_; //next
    int tag_;
    union
    {
        int ref;
        DataType atom;
        GenList<DataType> *hlink_;

    } value_;

public:
    friend class GenList<DataType>;
};

#endif