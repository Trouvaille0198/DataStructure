#ifndef LINK_STACK
#define LINK_STACK
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class LinkStack
{
protected:
    //不设头结点，_top为第一个节点
    Node<T> *_top;

public:
    LinkStack();
    virtual ~LinkStack();
    LinkStack(const LinkStack<T> &la);
    LinkStack<T> &operator=(const LinkStack<T> &la);

    void ClearStack();
    bool IsEmpty() const;
    int GetLength() const;
    void DisplayStack() const;

    void PushElem(const T &e);
    T TopElem();
    void PopElem();
};

template <class T>
LinkStack<T>::LinkStack()
//默认构造函数，将_top设置为NULL，表示栈为空
{
    _top = NULL;
}

template <class T>
LinkStack<T>::~LinkStack()
//析构函数，释放链表中所有结点的空间
{
    ClearStack();
}

template <class T>
LinkStack<T>::LinkStack(const LinkStack<T> &la)
//拷贝构造函数
{
    _top = new Node<T>;
    Node<T> *p, *q;
    Node<T> *cur = _top; //cur指向当前节点

    for (q = la._top; q != NULL; q = q->next) //q依次遍历la栈
    {
        p = new Node<T>(q->data); //利用p构建新节点，存放q值
        cur = p;
        cur = cur->next;
    }
}

template <class T>
LinkStack<T> &LinkStack<T>::operator=(const LinkStack<T> &la)
//赋值运算符重载
{
    if (&la != this)
    {
        ClearStack(); //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _top = new Node<T>;
        Node<T> *p, *q;
        Node<T> *cur = _top; //cur指向this的当前节点

        for (q = la._top; q != NULL; q = q->next) //q依次遍历la栈
        {
            p = new Node<T>(q->data); //利用p构建新节点，存放q值
            cur = p;
            cur = cur->next;
        }
    }
    return *this;
}

template <class T>
void LinkStack<T>::ClearStack()
//清空，从栈顶开始依次释放节点
{
    Node<T> *p;
    while (_top != NULL)
    {
        p = _top;
        _top = _top->next;
        delete p;
    }
}

template <class T>
bool LinkStack<T>::IsEmpty() const
//判空
{
    return _top == NULL;
}

template <class T>
int LinkStack<T>::GetLength() const
//求长度
{
    int count = 0;
    Node<T> *p;
    for (p = _top; p != NULL; p = p->next)
    {
        count++;
    }
    return count;
}

template <class T>
void LinkStack<T>::DisplayStack() const
//遍历
{
    Node<T> *p;
    cout << "自栈顶至栈底依次为：";
    for (p = _top; p->next != NULL; p = p->next)
    {
        cout << p->data << ", ";
    }
    cout << p->data << endl;
}

template <class T>
void LinkStack<T>::PushElem(const T &e)
//入栈
{
    Node<T> *p = new Node<T>(e, _top);
    if (p == NULL)
        cout << "动态内存耗尽！" << endl;
    else
        _top = p;
}

template <class T>
T LinkStack<T>::TopElem()
//取栈顶元素
{
    if (IsEmpty())
        cout << "链式栈已空" << endl;
    else
        return _top->data;
}

template <class T>
void LinkStack<T>::PopElem()
//出栈
{
    if (IsEmpty())
        cout << "链式栈已空，无法出栈！" << endl;
    else
    {
        Node<T> *p = _top; //取旧栈顶
        _top = _top->next; //_top指向新栈顶
        delete p;          //释放旧栈顶空间
    }
}

#endif