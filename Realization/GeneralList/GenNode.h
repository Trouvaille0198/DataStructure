#ifndef GENNODE_H
#define GENNODE_H
#include <bits/stdc++.h>
#include "GenList.h"
using namespace std;

enum NodeType
{
    _HEAD,
    _ATOM,
    _LIST
};

template <class DataType>
class GenNode
{
private:
    GenNode *tlink_; //next
    int tag_;
    union
    {
        int ref_;
        DataType atom_;
        GenList<DataType> *hlink_;

    } value_;

public:
    friend class GenList<DataType>;
    GenNode(DataType tag)
};

#endif