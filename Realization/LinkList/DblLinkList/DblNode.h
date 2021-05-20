#ifndef NODE
#define NODE
#include <bits/stdc++.h>
template <class T>
struct DblNode
{

    T data;           // 数据域
    DblNode<T> *next; // 指针域
    DblNode<T> *pre;

    DblNode(DblNode<T> *pnext = NULL, DblNode<T> *ppre = NULL); // 无参构造函数
    DblNode(T e, DblNode<T> *pnext = NULL, DblNode<T> *ppre = NULL);
};

template <class T>
DblNode<T>::DblNode(DblNode<T> *pnext, DblNode<T> *ppre)
//构造指针域为空的结点
{
    next = pnext;
    pre = ppre;
}

template <class T>
DblNode<T>::DblNode(T e, DblNode<T> *pnext, DblNode<T> *ppre)
//构造一个数据域为e和指针域为next的结点
{
    data = e;
    next = pnext;
    pre = ppre;
}

#endif
