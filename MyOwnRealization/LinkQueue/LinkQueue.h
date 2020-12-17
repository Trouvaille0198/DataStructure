#ifndef LINK_QUEUE
#define LINK_QUEUE

#include <bits/stdc++.h>
#include "../LinkList/Node.h"
using namespace std;

template <class DataType>
class LinkQueue
//带头结点
{
protected:
    Node<DataType> *_front, *_rear;

public:
    LinkQueue();
    virtual ~LinkQueue();
    LinkQueue(const LinkQueue<DataType> &q);
    LinkQueue<DataType> &operator=(const LinkQueue<DataType> &q);

    void ClearQueue();
    int GetLength() const;
    bool IsEmpty() const;
    void DisplayQueue() const;

    void EnterQueue(const DataType &e);
    DataType GetFront() const;
    void DeleteQueue();
};

template <class DataType>
LinkQueue<DataType>::LinkQueue()
{
    _rear = _front = new Node<DataType>;
}

template <class DataType>
LinkQueue<DataType>::~LinkQueue()
{
    ClearQueue();
    delete _front;
}

template <class DataType>
LinkQueue<DataType>::LinkQueue(const LinkQueue<DataType> &q)
//拷贝构造函数
{
    _rear = _front = new Node<DataType>;
    Node<DataType> *p;
    for (p = q._front->next; p != NULL; p = p->next)
    {
        EnterQueue(p->data);
    }
}

template <class DataType>
LinkQueue<DataType> &LinkQueue<DataType>::operator=(const LinkQueue<DataType> &q)
{
    if (&q != this)
    {
        ClearQueue();
        //_rear = _front = new Node<DataType>;
        Node<DataType> *p;
        for (p = q._front->next; p != NULL; p = p->next)
        {
            EnterQueue(p->data);
        }
    }
    return *this;
}

template <class DataType>
void LinkQueue<DataType>::ClearQueue()
//清空链队列，释放所有非空节点，_rear和_front都指向头节点
{
    Node<DataType> *p = _front->next; //保留头节点
    while (p != NULL)
    {
        _front->next = p->next;
        delete p;
        p = _front->next;
    }
    _rear = _front;
}

template <class DataType>
int LinkQueue<DataType>::GetLength() const
//求长度
{
    Node<DataType> *p = _front->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class DataType>
bool LinkQueue<DataType>::IsEmpty() const
{
    return _front == _rear;
}

template <class DataType>
void LinkQueue<DataType>::DisplayQueue() const
{
    if (IsEmpty())
    {
        cout << "链队列已空！" << endl;
    }
    else
    {
        Node<DataType> *p = _front->next;
        cout << "链队列的元素为：";
        while (p->next != NULL)
        {
            cout << p->data << ", ";
            p = p->next;
        }
        cout << p->data << endl;
    }
}

template <class DataType>
void LinkQueue<DataType>::EnterQueue(const DataType &e)
{
    Node<DataType> *p = new Node<DataType>(e);
    if (p) //判断系统空间是否足够
    {
        _rear->next = p;
        _rear = _rear->next;
    }
    else
    {
        cout << "系统空间不足，无法入队！" << endl;
    }
}

template <class DataType>
DataType LinkQueue<DataType>::GetFront() const
{
    return _front->next->data;
}

template <class DataType>
void LinkQueue<DataType>::DeleteQueue()
{
    if (IsEmpty())
    {
        cout << "链队列已空，无法出队！" << endl;
    }
    else
    {
        Node<DataType> *p = _front->next;
        _front->next = p->next;

        if (_rear == p)
            _rear = _front;
        delete p;
    }
}

#endif