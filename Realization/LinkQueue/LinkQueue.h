#ifndef LINK_QUEUE
#define LINK_QUEUE

#include <bits/stdc++.h>
#include "../LinkList/Node.h"
using namespace std;

template <class T>
class LinkQueue
//带头结点
{
protected:
    Node<T> *_front, *_rear;

public:
    LinkQueue();
    virtual ~LinkQueue();
    LinkQueue(const LinkQueue<T> &q);
    LinkQueue<T> &operator=(const LinkQueue<T> &q);

    void ClearQueue();
    int GetLength() const;
    bool IsEmpty() const;
    void DisplayQueue() const;

    void EnterQueue(const T &e);
    T GetFront() const;
    void DeleteQueue();
};

template <class T>
LinkQueue<T>::LinkQueue()
{
    _rear = _front = new Node<T>;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
    ClearQueue();
    delete _front;
}

template <class T>
LinkQueue<T>::LinkQueue(const LinkQueue<T> &q)
//拷贝构造函数
{
    _rear = _front = new Node<T>;
    Node<T> *p;
    for (p = q._front->next; p != NULL; p = p->next)
    {
        EnterQueue(p->data);
    }
}

template <class T>
LinkQueue<T> &LinkQueue<T>::operator=(const LinkQueue<T> &q)
{
    if (&q != this)
    {
        ClearQueue();
        //_rear = _front = new Node<T>;
        Node<T> *p;
        for (p = q._front->next; p != NULL; p = p->next)
        {
            EnterQueue(p->data);
        }
    }
    return *this;
}

template <class T>
void LinkQueue<T>::ClearQueue()
//清空链队列，释放所有非空节点，_rear和_front都指向头节点
{
    Node<T> *p = _front->next; //保留头节点
    while (p != NULL)
    {
        _front->next = p->next;
        delete p;
        p = _front->next;
    }
    _rear = _front;
}

template <class T>
int LinkQueue<T>::GetLength() const
//求长度
{
    Node<T> *p = _front->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template <class T>
bool LinkQueue<T>::IsEmpty() const
{
    return _front == _rear;
}

template <class T>
void LinkQueue<T>::DisplayQueue() const
{
    if (IsEmpty())
    {
        cout << "链队列已空！" << endl;
    }
    else
    {
        Node<T> *p = _front->next;
        cout << "链队列的元素为：";
        while (p->next != NULL)
        {
            cout << p->data << ", ";
            p = p->next;
        }
        cout << p->data << endl;
    }
}

template <class T>
void LinkQueue<T>::EnterQueue(const T &e)
{
    Node<T> *p = new Node<T>(e);
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

template <class T>
T LinkQueue<T>::GetFront() const
{
    return _front->next->data;
}

template <class T>
void LinkQueue<T>::DeleteQueue()
{
    if (IsEmpty())
    {
        cout << "链队列已空，无法出队！" << endl;
    }
    else
    {
        Node<T> *p = _front->next;
        _front->next = p->next;

        if (_rear == p)
            _rear = _front;
        delete p;
    }
}

#endif