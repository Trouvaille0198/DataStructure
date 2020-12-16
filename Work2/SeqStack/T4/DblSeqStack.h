//共享顺序栈
#ifndef SEQ_STACK
#define SEQ_STACK
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class DblSeqStack
{
protected:
    static const int DEFAULT_SIZE = 100;
    int _top1; //_top1从0开始
    int _top2; //_top2从_maxlen开始
    int _maxlen;
    DataType *_data;

public:
    DblSeqStack(int maxlen = DEFAULT_SIZE);                            //建立空栈
    DblSeqStack(const DblSeqStack<DataType> &sa);                      //拷贝构造函数
    virtual ~DblSeqStack();                                            //析构函数
    DblSeqStack<DataType> &operator=(const DblSeqStack<DataType> &sa); //赋值运算符重载

    void ClearStack();             //清空顺序表，暂时不知道有啥用
    int GetLength(int flag) const; //返回长度
    bool IsFull() const;           //判满
    bool IsEmpty(int flag) const;  //判空
    void DisplayStack() const;     //遍历显示顺序表

    void PushElem(const DataType &e, int flag); //入栈
    DataType TopElem(int flag);                 //取栈顶元素
    void PopElem(int flag);                     //出栈
};

template <class DataType>
DblSeqStack<DataType>::DblSeqStack(int maxlen) : _top1(-1), _top2(maxlen), _maxlen(maxlen)
//构造函数
{
    _data = new DataType[_maxlen]; //申请存储空间
}

template <class DataType>
DblSeqStack<DataType>::DblSeqStack(const DblSeqStack<DataType> &sa)
//拷贝构造函数
{
    _maxlen = sa._maxlen;
    _data = new DataType[_maxlen];
    _top1 = sa._top1;
    _top2 = sa._top2;
    for (int i = 0; i <= _top1; i++)
    {
        _data[i] = sa._data[i];
    }
    for (int i = _top2; i < _maxlen; i++)
    {
        _data[i] = sa._data[i];
    }
}

template <class DataType>
DblSeqStack<DataType>::~DblSeqStack()
//析构函数，不改变_maxlen和_top的值
{
    if (_data)
        delete[] _data; //释放存储空间
}

template <class DataType>
DblSeqStack<DataType> &DblSeqStack<DataType>::operator=(const DblSeqStack<DataType> &sa)
{
    if (&sa != this)
    {
        _maxlen = sa._maxlen;
        if (_data)
            delete[] _data; //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _data = new DataType[_maxlen];
        _top1 = sa._top1;
        _top2 = sa._top2;
        for (int i = 0; i <= _top1; i++)
        {
            _data[i] = sa._data[i];
        }
        for (int i = _top2; i < _maxlen; i++)
        {
            _data[i] = sa._data[i];
        }
    }
    return *this;
}

template <class DataType>
void DblSeqStack<DataType>::ClearStack()
{
    _top1 = -1;
    _top2 = _maxlen;
}

template <class DataType>
int DblSeqStack<DataType>::GetLength(int flag) const
{
    if (flag == 1)
        return _top1 + 1;
    else
        return _maxlen - _top2;
}

template <class DataType>
bool DblSeqStack<DataType>::IsEmpty(int flag) const
//判空
{
    if (flag == 1)
        return (_top1 == 0);
    else
        return (_top2 == _maxlen);
}

template <class DataType>
bool DblSeqStack<DataType>::IsFull() const
//判满
{
    return (_top1 == _top2 - 1);
}

template <class DataType>
void DblSeqStack<DataType>::DisplayStack() const
//遍历栈，从栈顶到栈底依次遍历
{
    if (IsEmpty(1))
        cout << "顺序栈1已空，无元素！" << endl;
    else
    {
        cout << "顺序栈1自栈顶至栈底依次为：";
        for (int i = _top1; i > 0; i--)
            cout << _data[i] << ", ";
        cout << _data[0] << endl;
    }
    if (IsEmpty(2))
        cout << "顺序栈2已空，无元素！" << endl;
    else
    {
        cout << "顺序栈2自栈顶至栈底依次为：";
        for (int i = _top2; i < _maxlen - 1; i++)
            cout << _data[i] << ", ";
        cout << _data[_maxlen - 1] << endl;
    }
}

template <class DataType>
void DblSeqStack<DataType>::PushElem(const DataType &e, int flag)
{
    if (IsFull())
        cout << "顺序栈已满！" << endl;
    else if (flag == 1)
        _data[++_top1] = e;
    else if (flag == 2)
        _data[--_top2] = e;
}

template <class DataType>
DataType DblSeqStack<DataType>::TopElem(int flag)
//取栈顶元素
{
    if (flag == 1)
    {
        if (IsEmpty(1))
        {
            cout << "顺序栈1已空，无法取出栈顶元素！" << endl;
            return NULL;
        }
        else
        {
            return _data[_top1];
        }
    }
    if (flag == 2)
    {
        if (IsEmpty(2))
        {
            cout << "顺序栈2已空，无法取出栈顶元素！" << endl;
            return NULL;
        }
        else
        {
            return _data[_top2];
        }
    }
}

template <class DataType>
void DblSeqStack<DataType>::PopElem(int flag)
//出栈
{
    if (flag == 1)
    {
        if (IsEmpty(1))
        {
            cout << "顺序栈1已空，无法继续出栈！" << endl;
        }
        else
        {
            _top1--;
        }
    }
    if (flag == 2)
    {
        if (IsEmpty(2))
        {
            cout << "顺序栈2已空，无法继续出栈！" << endl;
        }
        else
        {
            _top2++;
        }
    }
}

#endif