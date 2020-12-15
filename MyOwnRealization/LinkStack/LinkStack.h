#ifndef LINK_STACK
#define LINK_STACK
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class LinkStack
{
protected:
    //不设头结点，_top为第一个节点
    Node<DataType> *_top;

public:
    LinkStack();
    virtual ~LinkStack();
    LinkStack(const LinkStack<DataType> &la);
    LinkStack<DataType> &operator=(const LinkStack<DataType> &la);

    void ClearStack();
    bool IsEmpty() const;
    int GetLength() const;
    void DisplayStack() const;

    void PushElem(const DataType &e);
    DataType TopElem();
    void PopElem();
};

template <class DataType>
LinkStack<DataType>::LinkStack()
//默认构造函数，将_top设置为NULL，表示栈为空
{
    _top = NULL;
}

template <class DataType>
LinkStack<DataType>::~LinkStack()
//析构函数，释放链表中所有结点的空间
{
    ClearStack();
}

template <class DataType>
LinkStack<DataType>::LinkStack(const LinkStack<DataType> &la)
//拷贝构造函数
{
    _top = new Node<DataType>;
    Node<DataType> *p, *q;
    Node<DataType> *cur = _top; //cur指向当前节点

    for (q = la._top; q != NULL; q = q->next) //q依次遍历la栈
    {
        p = new Node<DataType>(q->data); //利用p构建新节点，存放q值
        cur = p;
        cur = cur->next;
    }
}

template <class DataType>
LinkStack<DataType> &LinkStack<DataType>::operator=(const LinkStack<DataType> &la)
//赋值运算符重载
{
    if (&la != this)
    {
        ClearStack(); //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _top = new Node<DataType>;
        Node<DataType> *p, *q;
        Node<DataType> *cur = _top; //cur指向this的当前节点

        for (q = la._top; q != NULL; q = q->next) //q依次遍历la栈
        {
            p = new Node<DataType>(q->data); //利用p构建新节点，存放q值
            cur = p;
            cur = cur->next;
        }
    }
    return *this;
}

template <class DataType>
void LinkStack<DataType>::ClearStack()
//清空，从栈顶开始依次释放节点
{
    Node<DataType> *p;
    while (_top != NULL)
    {
        p = _top;
        _top = _top->next;
        delete p;
    }
}

template <class DataType>
bool LinkStack<DataType>::IsEmpty() const
//判空
{
    return _top == NULL;
}

template <class DataType>
int LinkStack<DataType>::GetLength() const
//求长度
{
    int count = 0;
    Node<DataType> *p;
    for (p = _top; p != NULL; p = p->next)
    {
        count++;
    }
    return count;
}

template <class DataType>
void LinkStack<DataType>::DisplayStack() const
//遍历
{
    Node<DataType> *p;
    cout << "自栈顶至栈底依次为：";
    for (p = _top; p->next != NULL; p = p->next)
    {
        cout << p->data << ", ";
    }
    cout << p->data << endl;
}

template <class DataType>
void LinkStack<DataType>::PushElem(const DataType &e)
//入栈
{
    Node<DataType> *p = new Node<DataType>(e, _top);
    if (p == NULL)
        cout << "动态内存耗尽！" << endl;
    else
        _top = p;
}

template <class DataType>
DataType LinkStack<DataType>::TopElem()
//取栈顶元素
{
    if (IsEmpty())
        cout << "链式栈已空" << endl;
    else
        return _top->data;
}

template <class DataType>
void LinkStack<DataType>::PopElem()
//出栈
{
    if (IsEmpty())
        cout << "链式栈已空，无法出栈！" << endl;
    else
    {
        Node<DataType> *p = _top; //取旧栈顶
        _top = _top->next;        //_top指向新栈顶
        delete p;                 //释放旧栈顶空间
    }
}

#endif