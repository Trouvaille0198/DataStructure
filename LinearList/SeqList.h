#ifndef SeqList_H
#define SeqList_H
#include <bits/stdc++.h>
using namespace std;
#define NOT_PRESENT 0;
#define ENTRY_FOUND 1;
#define RANGE_ERROR 0;
#define SUCCESS 1;
#define OVER_FLOW 0;
typedef int Status;

template <class ElemType>
class SeqList
{
protected:
    //数据成员
    int _length;      //当前长度
    int _maxLength;   //当前容量
    ElemType *_elems; //元素存储空间首地址
public:
    //基本成员函数
    SeqList(int size = DEFAULT_SIZE);                                   //构造函数，构造空表
    SeqList(ElemType v[], int currentSize, int maxSize = DEFAULT_SIZE); //构造函数，根据v[]构造
    virtual ~SeqList();                                                 //析构函数
    SeqList(const SeqList<ElemType> &sa);                               //拷贝构造函数
    SeqList<ElemType> &operator=(const SeqList<ElemType> &sa);          //赋值语句重载
    //基本操作
    int GetLength() const;                                //取长度
    bool IsEmpty() const;                                 //判空
    void Clear();                                         //清空
    void Traverse(void (*Visit)(const ElemType &)) const; //遍历
    int LocateElem(const ElemType &e) const;              //求指定元素的位置索引
    Status GetElem(int i, ElemType &e) const;             //取第i个元素的值
    Status SetElem(int i, const ElemType &e);             //修改第i个元素的值
    Status DeleteElem(int i, ElemType &e);                //删除第i个元素
    Status InsertElem(int i, const ElemType &e);          //在第i个位置插入元素
    Status InsertElem(const ElemType &e);                 //在表尾插入元素
};

template <class ElemType>
SeqList<ElemType>::SeqList(int size)
{
    _elems = new ElemType[size];
    assert(_elems); //若申请存储空间失败，则程序终止
    _maxLength = size;
    _length = 0;
}

template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int currentSize, int maxSize)
{
    _elems = new ElemType[maxSize];
    assert(_elems);
    _maxLength = maxSize;
    _length = currentSize;
    for (int i = 0; i < _length; i++)
    {
        _elems[i] = v[i];
    }
}

template <class ElemType>
SeqList<ElemType>::~SeqList()
{
    delete[] _elems;
}

template <class ElemType>
void SeqList<ElemType>::Clear()
{
    _length = 0;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for (int i = 0; i < _length; i++)
    {
        (*visit)(_elems[i]);
    }
}

template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
    for (int i = 0; i < _length; i++)
    {
        if (_elems[i] == e)
            return ++i;
    }
    return 0;
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i < 1 || i > _length)
        return NOT_PRESENT;
    else
    {
        e = _elems[i - 1];
        return ENTRY_FOUND;
    }
}

template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 1 || i > _length)
        return RANGE_ERROR;
    else
    {
        _elems[i - 1] = e;
        return SUCCESS;
    }
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
    if (i < 1 || i > _length)
        return RANGE_ERROR;
    else
    {
        e = _elems[i - 1];
        for (int j = i; j < _length; j++)
            _elems[j - 1] = _elems[j]; //被删除元素后的元素依次左移一个位置
        _length--;
        return SUCCESS;
    }
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (_length = _maxLength)
        return OVER_FLOW;
    else if (i < 1 || i > _length + 1)
        return RANGE_ERROR;
    else
    {
        for (int j = _length; j >= i; j--)
            _elems[j] = _elems[j - 1]; //插入位置之后的元素右移
        _elems[i - 1] = e;             //将e复制到顺序表第i个位置
        _length++;                     //插入后元素个数加1
        return SUCCESS;
    }
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
{
    if (_length == _maxLength)
        return OVER_FLOW;
    else
    {
        _elems[_length] = e;
        _length++;
        return SUCCESS;
    }
}

#endif