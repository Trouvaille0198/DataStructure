#ifndef LINK_LIST
#define LINK_LIST
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class LinkList
{
protected:
    Node<T> *_head;
    int _length;

public:
    LinkList();
    LinkList(T *a, int length);
    virtual ~LinkList();
    LinkList(const LinkList<T> &la);
    LinkList<T> &operator=(const LinkList<T> &la);

    void ClearList();
    int GetLength() const;
    bool IsEmpty() const;
    int LocateElem(const T &e) const;
    void DisplayList() const;

    T GetElem(int i) const;
    void SetElem(int i, const T &e);
    void InsertElem(int i, const T &e); //前插
    void InsertElem(const T &e);        //表尾插
    void DeleteElem(int i);
};

template <class T>
LinkList<T>::LinkList()
{
    _head = new Node<T>;
    _length = 0;
}

template <class T>
LinkList<T>::LinkList(T *a, int length)
{
    _length = length;
    Node<T> *p;
    p = _head = new Node<T>;
    for (int i = 0; i < _length; i++) //p指针一直后移，依次构建新节点
    {
        p->next = new Node<T>(a[i]);
        p = p->next;
    }
}

template <class T>
LinkList<T>::~LinkList()
//销毁单链表,多了删除头节点这一步
{
    ClearList();  // 清空单链表
    delete _head; // 释放头结点所指空间
}

template <class T>
LinkList<T>::LinkList(const LinkList<T> &la)
//拷贝构造函数，由单链表la构造新单链表
{
    T e;
    _length = 0;
    _head = new Node<T>;

    for (int i = 1; i <= la._length; i++)
    {
        e = la.GetElem(i);
        InsertElem(e);
    }
}

template <class T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &la)
//重载赋值运算符，将单链表la赋值给当前单链表
{
    if (&la != this)
    {
        T e;
        ClearList(); //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤

        for (int i = 1; i <= la._length; i++)
        {
            e = la.GetElem(i);
            InsertElem(e);
        }
    }
    return *this;
}

template <class T>
void LinkList<T>::ClearList()
//清空链表，删除单链表中所有元素结点
{
    Node<T> *p = _head->next;
    while (p != NULL)
    {
        _head->next = p->next; //从表中移除_head后的第一个节点
        delete p;              //删除此节点
        p = _head->next;       //p继续指向_head后的第一个节点
    }
    _length = 0;
}

template <class T>
int LinkList<T>::GetLength() const
//返回单链表的长度
{
    return _length;
}

template <class T>
bool LinkList<T>::IsEmpty() const
//如单链表为空，则返回true，否则返回false
{
    return _head->next == NULL;
}

template <class T>
int LinkList<T>::LocateElem(const T &e) const
//元素定位
{
    Node<T> *p = _head->next;
    for (int i = 1; p != NULL; p = p->next, i++)
    {
        if (p->data == e)
            return i;
    }
    cout << "表中不存在该元素！" << endl;
    return 0;
}

template <class T>
void LinkList<T>::DisplayList() const
//遍历链表
{
    Node<T> *p = _head->next;
    while (p->next != NULL)
    {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << p->data << endl;
}

template <class T>
T LinkList<T>::GetElem(int i) const
//当单链表存在第i个元素时，返回其值
{
    if (i >= 1 && i <= _length)
    {
        Node<T> *p = _head->next;
        for (int j = 1; j < i; j++) //遍历，直到指定位置i
            p = p->next;
        return p->data;
    }
    cout << "位置不合理！" << endl;
    return NULL; //此处有Warning
}

template <class T>
void LinkList<T>::SetElem(int i, const T &e)
//将单链表的第i个位置的元素赋值为e
{
    if (i >= 1 && i <= _length)
    {
        Node<T> *p = _head->next;
        for (int j = 1; j < i; j++) //遍历，直到指定位置i
            p = p->next;
        p->data = e; //修改第i个元素的值为e
    }
    else
        cout << "位置不合理！" << endl;
}

template <class T>
void LinkList<T>::InsertElem(int i, const T &e)
//在单链表的第i个位置前插入元素e
{
    if (i < 1 || i >= _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        Node<T> *p = _head, *q;     //这里p指向头节点
        for (int j = 1; j < i; j++) //用p遍历，直到指定位置i前面一个位置
            p = p->next;
        q = new Node<T>(e, p->next); //用q创造新结点，并且连接好指针域
        p->next = q;
        _length++;
    }
}

template <class T>
void LinkList<T>::InsertElem(const T &e)
//在单链表表尾插入元素e
{
    Node<T> *p = _head, *q;
    q = new Node<T>(e, NULL); //用q创造新结点
    while (p->next != NULL)   //p指向表尾节点
    {
        p = p->next;
    }
    p->next = q;
    _length++;
}

template <class T>
void LinkList<T>::DeleteElem(int i)
//删除单链表的第i个位置的元素
{
    if (IsEmpty())
    {
        cout << "单链表已空,不可删除元素!" << endl;
        return;
    }
    if (i < 1 || i > _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        Node<T> *p = _head->next, *q;
        for (int j = 1; j < i - 1; j++) //用p遍历，直到指定位置i前面一个位置
            p = p->next;
        q = p->next;       //用q标记待删除的节点
        p->next = q->next; //将待删除节点从链表上摘除
        delete q;          //释放被删结点
        _length--;
    }
}

#endif