#ifndef SEQ_LIST
#define SEQ_LIST
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class SeqList
{
protected:
    static const int DEFAULT_SIZE = 100;
    int _length;
    int _maxlen;
    DataType *_data;

public:
    SeqList(int maxlen = DEFAULT_SIZE);                          //建立空表
    SeqList(DataType *a, int length, int maxlen = DEFAULT_SIZE); //根据数组创建新表
    SeqList(const SeqList<DataType> &sa);                        //拷贝构造函数
    virtual ~SeqList();                                          //析构函数
    SeqList<DataType> &operator=(const SeqList<DataType> &sa);   //赋值运算符重载

    void ClearList();                        //清空顺序表，暂时不知道有啥用
    int GetLength() const;                   //返回长度
    bool IsEmpty() const;                    //判空
    bool IsFull() const;                     //判满
    void DisplayList() const;                //遍历显示顺序表
    int LocateElem(const DataType &e) const; //元素定位，返回指定元素位置

    DataType GetElem(int i) const;             //查找元素，返回查找的元素
    void SetElem(int i, const DataType &e);    //修改i位置的元素值
    void InsertElem(int i, const DataType &e); //在i位置插入新元素
    void InsertElem(const DataType &e);        //在末尾插入新元素
    void DeleteElemByIndex(int i);             //删除i位置的元素
    void DeleteElemByValue(const DataType &e); //删除指定元素
};

/*建立一个有默认最大长度的空表*/
template <class DataType>
SeqList<DataType>::SeqList(int maxlen) : _length(0), _maxlen(maxlen)
{
    _data = new DataType[_maxlen]; //申请存储空间
}

template <class DataType>
SeqList<DataType>::SeqList(DataType *a, int length, int maxlen) : _length(length), _maxlen(maxlen)
{
    _data = new DataType[maxlen];
    for (int i = 0; i < length; i++)
        _data[i] = a[i];
}

template <class DataType>
SeqList<DataType>::SeqList(const SeqList<DataType> &sa)
{
    DataType e;
    _maxlen = sa._maxlen;
    _data = new DataType[_maxlen];
    _length = 0;
    for (int i = 1; i <= sa._length; i++)
    {
        e = sa.GetElem(i);
        InsertElem(e);
    }
}

template <class DataType>
SeqList<DataType>::~SeqList()
{
    if (_data)
        delete[] _data;
}

template <class DataType>
SeqList<DataType> &SeqList<DataType>::operator=(const SeqList<DataType> &sa)
{
    if (&sa != this)
    {
        DataType e;
        _maxlen = sa._maxlen;
        if (_data)
            delete[] _data; //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _data = new DataType[_maxlen];
        _length = 0;
        for (int i = 1; i <= sa._length; i++)
        {
            e = sa.GetElem(i);
            InsertElem(e);
        }
    }
    return *this;
}

template <class DataType>
void SeqList<DataType>::ClearList()
{
    _length = 0; //直接使长度清零即可
}

template <class DataType>
int SeqList<DataType>::GetLength() const
{
    return _length;
}

template <class DataType>
bool SeqList<DataType>::IsEmpty() const
{
    return (_length == 0);
}

template <class DataType>
bool SeqList<DataType>::IsFull() const
{
    return (_length == _maxlen);
}

template <class DataType>
void SeqList<DataType>::DisplayList() const
{
    for (int i = 0; i < _length - 1; i++)
        cout << _data[i] << ", ";
    cout << _data[_length - 1] << endl;
}

template <class DataType>
int SeqList<DataType>::LocateElem(const DataType &e) const
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == e)
            return i + 1;
    }
    cout << "表中不存在该元素！" << endl;
    return 0; //不存在则返回0
}

template <class DataType>
DataType SeqList<DataType>::GetElem(int i) const
{
    if (i >= 1 && i <= _length)
        return _data[i - 1]; //第i个元素的数组索引为i-1
    cout << "位置不合理！" << endl;
    return NULL; //此处有Warning
}

template <class DataType>
void SeqList<DataType>::SetElem(int i, const DataType &e)
{
    if (i > 0 && i <= _length)
        _data[i - 1] = e;
    else
        cout << "位置不合理！" << endl;
}

template <class DataType>
void SeqList<DataType>::InsertElem(int i, const DataType &e)
{
    if (IsFull())
    {
        cout << "线性表已满,不可添加新元素!" << endl;
        return;
    }
    if (i < 1 || i > _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        for (int j = _length; j >= i; j--)
        {
            _data[j] = _data[j - 1];
        }
        _data[i - 1] = e;
        _length++;
    }
}

template <class DataType>
void SeqList<DataType>::InsertElem(const DataType &e)
{
    if (IsFull())
    {
        cout << "线性表已满,不可添加新元素!" << endl;
        return;
    }
    _data[_length] = e;
    _length++;
}

template <class DataType>
void SeqList<DataType>::DeleteElemByIndex(int i)
{
    if (IsEmpty())
    {
        cout << "线性表已空,不可删除元素!" << endl;
        return;
    }
    if (i < 1 || i > _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    for (int j = i - 1; j < _length - 1; j++)
    {
        _data[j] = _data[j + 1];
    }
    _length--;
}

template <class DataType>
void SeqList<DataType>::DeleteElemByValue(const DataType &e)
{
    int i = LocateElem(e);
    DeleteElemByIndex(i);
}

#endif