#ifndef LINK_LIST
#define LINK_LIST
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class LinkList
{
protected:
    Node<DataType> *_head;
    int _length;

public:
    LinkList();
    LinkList(DataType *a, int length);
    Virtual ~LinkList();
    LinkList(const LinkList<DataType> &la);
    LinkList<DataType> &operator=(const LinkList<DataType> &la);
};

#endif