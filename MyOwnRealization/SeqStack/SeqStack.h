#ifndef SEQ_STACK
#define SEQ_STACK
#include <bits/stdc++.h>
using namespace std;

template <class T>
class SeqStack
{
protected:
    static const int DEFAULT_SIZE = 100;
    int _top; //_top从0开始
    int _maxlen;
    T *_data;

public:
    SeqStack(int maxlen = DEFAULT_SIZE);           //建立空栈
    SeqStack(const SeqStack<T> &sa);               //拷贝构造函数
    virtual ~SeqStack();                           //析构函数
    SeqStack<T> &operator=(const SeqStack<T> &sa); //赋值运算符重载

    void ClearStack();         //清空顺序表，暂时不知道有啥用
    int GetLength() const;     //返回长度
    bool IsFull() const;       //判满
    bool IsEmpty() const;      //判空
    void DisplayStack() const; //遍历显示顺序表

    void PushElem(const T &e); //入栈
    T TopElem();               //取栈顶元素
    void PopElem();            //出栈
};

template <class T>
SeqStack<T>::SeqStack(int maxlen) : _top(-1), _maxlen(maxlen)
//构造函数
{
    _data = new T[_maxlen]; //申请存储空间
}

template <class T>
SeqStack<T>::SeqStack(const SeqStack<T> &sa)
//拷贝构造函数
{
    _maxlen = sa._maxlen;
    _data = new T[_maxlen];
    _top = sa._top;
    for (int i = 0; i < sa.GetLength(); i++)
    {
        _data[i] = sa._data[i];
    }
}

template <class T>
SeqStack<T>::~SeqStack()
//析构函数，不改变_maxlen和_top的值
{
    if (_data)
        delete[] _data; //释放存储空间
}

template <class T>
SeqStack<T> &SeqStack<T>::operator=(const SeqStack<T> &sa)
{
    if (&sa != this)
    {
        _maxlen = sa._maxlen;
        if (_data)
            delete[] _data; //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _data = new T[_maxlen];
        _top = sa._top;
        for (int i = 0; i < sa.GetLength(); i++)
        {
            _data[i] = sa._data[i];
        }
    }
    return *this;
}

template <class T>
void SeqStack<T>::ClearStack()
{
    _top = -1;
}

template <class T>
int SeqStack<T>::GetLength() const
{
    return _top + 1;
}

template <class T>
bool SeqStack<T>::IsEmpty() const
//判空
{
    return (_top == -1);
}

template <class T>
bool SeqStack<T>::IsFull() const
//判满
{
    return (_top == _maxlen - 1);
}

template <class T>
void SeqStack<T>::DisplayStack() const
//遍历栈，从栈顶到栈底依次遍历
{
    if (IsEmpty())
        cout << "顺序栈已空，无元素！" << endl;
    else
    {
        cout << "自栈顶至栈底依次为：";
        for (int i = _top; i > 0; i--)
            cout << _data[i] << ", ";
        cout << _data[0] << endl; //此举避免末尾逗号的出现
    }
}

template <class T>
void SeqStack<T>::PushElem(const T &e)
//入栈
{
    if (IsFull())
        cout << "顺序栈已满！" << endl;
    else
        _data[++_top] = e;
}

template <class T>
T SeqStack<T>::TopElem()
//取栈顶元素
{
    if (IsEmpty())
    {
        cout << "顺序栈已空，无法取出栈顶元素！" << endl;
        //return NULL;
    }
    else
    {
        return _data[_top];
    }
}

template <class T>
void SeqStack<T>::PopElem()
//出栈
{
    if (IsEmpty())
    {
        cout << "顺序栈已空，无法继续出栈！" << endl;
        return;
    }
    else
    {
        _top--;
    }
}

#endif