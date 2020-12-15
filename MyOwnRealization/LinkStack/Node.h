#ifndef NODE
#define NODE
#include <bits/stdc++.h>
template <class DataType>
struct Node
{

    DataType data;        // 数据域
    Node<DataType> *next; // 指针域

    Node(Node<DataType> *pnext = NULL); // 无参构造函数
    Node(DataType e, Node<DataType> *pnext = NULL);
};

template <class DataType>
Node<DataType>::Node(Node<DataType> *pnext)
//构造指针域为空的结点
{
    next = pnext;
}

template <class DataType>
Node<DataType>::Node(DataType e, Node<DataType> *pnext)
//构造一个数据域为e和指针域为next的结点
{
    data = e;
    next = pnext;
}

#endif
