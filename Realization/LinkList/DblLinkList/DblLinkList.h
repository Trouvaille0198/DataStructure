// 带头结点的双向非循环链表
#ifndef DBL_LINK_LIST
#define DBL_LINK_LIST
#include "DblNode.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class DblLinkList
{
protected:
    DblNode<T> *_head;
    int _length;

public:
    DblLinkList();
    DblLinkList(T *a, int length);
    virtual ~DblLinkList();
    DblLinkList(const DblLinkList<T> &la);
    DblLinkList<T> &operator=(const DblLinkList<T> &la);

    void ClearList();
    int GetLength() const;
    bool IsEmpty() const;
    int LocateElem(const T &e) const;
    void Display() const;

    T GetElem(int i) const;
    void SetElem(int i, const T &e);
    void InsertElem(int i, const T &e); //前插
    void InsertElem(const T &e);        //表尾插
    void DeleteElem(int i);
    void ExchangeElem(int i, int j);
};

template <class T>
DblLinkList<T>::DblLinkList()
{
    _head = new DblNode<T>;
    _length = 0;
}

template <class T>
DblLinkList<T>::DblLinkList(T *a, int length)
{
    _length = length;
    DblNode<T> *p;
    p = _head = new DblNode<T>;
    for (int i = 0; i < _length; i++) //p指针一直后移，依次构建新节点
    {
        p->next = new DblNode<T>(a[i]);
        p->next->pre = p;
        p = p->next;
    }
}

template <class T>
DblLinkList<T>::~DblLinkList()
//销毁双向链表,多了删除头节点这一步
{
    ClearList();  // 清空双向链表
    delete _head; // 释放头结点所指空间
}

template <class T>
DblLinkList<T>::DblLinkList(const DblLinkList<T> &la)
//拷贝构造函数，由链表la构造新链表
{
    T e;
    _length = 0;
    _head = new DblNode<T>;

    for (int i = 0; i < la._length; i++)
    {
        e = la.GetElem(i);
        InsertElem(e);
    }
}

template <class T>
DblLinkList<T> &DblLinkList<T>::operator=(const DblLinkList<T> &la)
//重载赋值运算符，将双向链表la赋值给当前双向链表
{
    if (&la != this)
    {
        T e;
        ClearList(); //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤

        for (int i = 0; i < la._length; i++)
        {
            e = la.GetElem(i);
            InsertElem(e);
        }
    }
    return *this;
}

template <class T>
void DblLinkList<T>::ClearList()
//清空链表，删除双向链表中所有元素结点
{
    DblNode<T> *p = _head->next;
    while (p != NULL)
    {
        _head->next = p->next; //从表中移除_head后的第一个节点
        delete p;              //删除此节点
        p = _head->next;       //p继续指向_head后的第一个节点
    }
    _length = 0;
}

template <class T>
int DblLinkList<T>::GetLength() const
//返回双向链表的长度
{
    return _length;
}

template <class T>
bool DblLinkList<T>::IsEmpty() const
//如双向链表为空，则返回true，否则返回false
{
    return _head->next == NULL;
}

template <class T>
int DblLinkList<T>::LocateElem(const T &e) const
//元素定位
{
    DblNode<T> *p = _head->next;
    for (int i = 1; p != NULL; p = p->next, i++)
    {
        if (p->data == e)
            return i;
    }
    cout << "表中不存在该元素！" << endl;
    return 0;
}

template <class T>
void DblLinkList<T>::Display() const
//遍历链表
{
    DblNode<T> *p = _head->next;
    while (p->next != NULL)
    {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << p->data << endl;
}

template <class T>
T DblLinkList<T>::GetElem(int i) const
// 返回下标为i的值
{
    if (i >= 0 && i < _length)
    {
        DblNode<T> *p = _head->next;
        for (int j = 0; j < i; j++) //遍历，直到指定位置i
            p = p->next;
        return p->data;
    }
    cout << "位置不合理！" << endl;
    return NULL; //此处有Warning
}

template <class T>
void DblLinkList<T>::SetElem(int i, const T &e)
//将双向链表的第i个位置的元素赋值为e
{
    if (i >= 1 && i <= _length)
    {
        DblNode<T> *p = _head->next;
        for (int j = 1; j < i; j++) //遍历，直到指定位置i
            p = p->next;
        p->data = e; //修改第i个元素的值为e
    }
    else
        cout << "位置不合理！" << endl;
}

template <class T>
void DblLinkList<T>::InsertElem(int i, const T &e)
//在双向链表的第i个位置前插入元素e
{
    if (i < 0 || i > _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        DblNode<T> *p = _head, *q;      //这里p指向头节点
        for (int j = 0; j < i - 1; j++) //用p遍历，直到指定位置i前面一个位置
            p = p->next;
        q = new DblNode<T>(e, p->next, p); //用q创造新结点，并且连接好指针域
        p->next = q;
        q->next->pre = q;

        _length++;
    }
}

template <class T>
void DblLinkList<T>::InsertElem(const T &e)
//在双向链表表尾插入元素e
{
    DblNode<T> *p = _head, *q;
    q = new DblNode<T>(e);  //用q创造新结点
    while (p->next != NULL) //p指向表尾节点
    {
        p = p->next;
    }
    p->next = q;
    q->pre = p;
    _length++;
}

template <class T>
void DblLinkList<T>::DeleteElem(int i)
//删除双向链表的第i个位置的元素
{
    if (IsEmpty())
    {
        cout << "双向链表已空,不可删除元素!" << endl;
        return;
    }
    if (i < 1 || i > _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        DblNode<T> *p = _head->next, *q;
        for (int j = 1; j < i - 1; j++) //用p遍历，直到指定位置i前面一个位置
            p = p->next;
        q = p->next;       //用q标记待删除的节点
        p->next = q->next; //将待删除节点从链表上摘除
        p->next->pre = p;
        delete q; //释放被删结点
        _length--;
    }
}

template <class T>
void DblLinkList<T>::ExchangeElem(int i, int j)
// 交换下标为i和j的两个元素
{
    DblNode<T> *p, *q;
    p = q = _head->next;
    for (int k = 0; k < i; k++)
        p = p->next;
    for (int k = 0; k < j; k++)
        q = q->next;
    T temp = p->data;
    p->data = q->data;
    q->data = temp;
}

#endif