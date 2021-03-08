#ifndef NODE
#define NODE
#include <bits/stdc++.h>
template <class T>
struct Node
{

    T data;        // 数据域
    Node<T> *next; // 指针域

    Node(Node<T> *pnext = NULL); // 无参构造函数
    Node(T e, Node<T> *pnext = NULL);
};

template <class T>
Node<T>::Node(Node<T> *pnext)
//构造指针域为空的结点
{
    next = pnext;
}

template <class T>
Node<T>::Node(T e, Node<T> *pnext)
//构造一个数据域为e和指针域为next的结点
{
    data = e;
    next = pnext;
}

#endif
