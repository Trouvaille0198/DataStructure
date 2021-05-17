#ifndef SEQ_LIST
#define SEQ_LIST
#include <bits/stdc++.h>
using namespace std;

template <class T>
class SeqList
{

public:
    static const int DEFAULT_SIZE = 100;
    int _length;
    int _maxlen;
    T *_data;

    SeqList(int maxlen = DEFAULT_SIZE);                   //建立空表
    SeqList(T *a, int length, int maxlen = DEFAULT_SIZE); //根据数组创建新表
    SeqList(const SeqList<T> &sa);                        //拷贝构造函数
    virtual ~SeqList();                                   //析构函数
    SeqList<T> &operator=(const SeqList<T> &sa);          //赋值运算符重载

    void ClearList();                 //清空顺序表，暂时不知道有啥用
    int GetLength() const;            //返回长度
    bool IsEmpty() const;             //判空
    bool IsFull() const;              //判满
    void DisplayList() const;         //遍历显示顺序表
    int LocateElem(const T &e) const; //元素定位，返回指定元素位置

    T GetElem(int i) const;             //查找元素，返回查找的元素
    void SetElem(int i, const T &e);    //修改i位置的元素值
    void InsertElem(int i, const T &e); //在i位置插入新元素
    void InsertElem(const T &e);        //在末尾插入新元素
    void DeleteElemByIndex(int i);      //删除i位置的元素
    void DeleteElemByValue(const T &e); //删除指定元素
    void ExchangeElem(int i, int j);    //交换元素
};

/*建立一个有默认最大长度的空表*/
template <class T>
SeqList<T>::SeqList(int maxlen) : _length(0), _maxlen(maxlen)
{
    _data = new T[_maxlen]; //申请存储空间
}

template <class T>
SeqList<T>::SeqList(T *a, int length, int maxlen) : _length(length), _maxlen(maxlen)
{
    _data = new T[maxlen];
    for (int i = 0; i < length; i++)
        _data[i] = a[i];
}

template <class T>
SeqList<T>::SeqList(const SeqList<T> &sa)
{
    T e;
    _maxlen = sa._maxlen;
    _data = new T[_maxlen];
    _length = 0;
    for (int i = 0; i < sa._length; i++)
    {
        e = sa.GetElem(i);
        InsertElem(e);
    }
}

template <class T>
SeqList<T>::~SeqList()
{
    if (_data)
        delete[] _data;
}

template <class T>
SeqList<T> &SeqList<T>::operator=(const SeqList<T> &sa)
{
    if (&sa != this)
    {
        T e;
        _maxlen = sa._maxlen;
        if (_data)
            delete[] _data; //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _data = new T[_maxlen];
        _length = 0;
        for (int i = 0; i < sa._length; i++)
        {
            e = sa.GetElem(i);
            InsertElem(e);
        }
    }
    return *this;
}

template <class T>
void SeqList<T>::ClearList()
{
    _length = 0; //直接使长度清零即可
}

template <class T>
int SeqList<T>::GetLength() const
{
    return _length;
}

template <class T>
bool SeqList<T>::IsEmpty() const
{
    return (_length == 0);
}

template <class T>
bool SeqList<T>::IsFull() const
{
    return (_length == _maxlen);
}

template <class T>
void SeqList<T>::DisplayList() const
{
    for (int i = 0; i < _length - 1; i++)
        cout << _data[i] << ", ";
    cout << _data[_length - 1] << endl;
}

template <class T>
int SeqList<T>::LocateElem(const T &e) const
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == e)
            return i;
    }
    cout << "表中不存在该元素！" << endl;
    return -1; //不存在则返回0
}

template <class T>
T SeqList<T>::GetElem(int i) const
{
    if (i >= 0 && i < _length)
        return _data[i];
    else
    {
        cout << "无法获取元素, 位置不合理！" << endl;
        //return NULL; //此处有Warning
    }
}

template <class T>
void SeqList<T>::SetElem(int i, const T &e)
{
    if (i >= 0 && i < _length)
        _data[i] = e;
    else
        cout << "无法设置元素, 位置不合理！" << endl;
}

template <class T>
void SeqList<T>::InsertElem(int i, const T &e)
{
    if (IsFull())
    {
        cout << "线性表已满,不可添加新元素!" << endl;
        return;
    }
    if (i < 0 || i >= _length)
    {
        cout << "位置不合理！" << endl;
        return;
    }
    else
    {
        for (int j = _length; j > i; j--) //i及其后的元素向后移动一格
        {
            _data[j] = _data[j - 1];
        }
        _data[i] = e;
        _length++; //总长+1
    }
}

template <class T>
void SeqList<T>::InsertElem(const T &e)
{
    if (IsFull())
    {
        cout << "线性表已满,不可添加新元素!" << endl;
        return;
    }
    _data[_length] = e;
    _length++;
}

template <class T>
void SeqList<T>::DeleteElemByIndex(int i)
{
    if (IsEmpty())
    {
        cout << "线性表已空,不可删除元素!" << endl;
        return;
    }
    if (i < 0 || i >= _length)
    {
        cout << "无法删除, 位置不合理！" << endl;
        return;
    }
    for (int j = i; j < _length - 1; j++)
    {
        _data[j] = _data[j + 1];
    }
    _length--;
}

template <class T>
void SeqList<T>::DeleteElemByValue(const T &e)
{
    int i = LocateElem(e);
    DeleteElemByIndex(i);
}

template <class T>
void SeqList<T>::ExchangeElem(int i, int j)
{
    if (i >= 0 && i < _length && j >= 0 && j < _length)
    {
        T temp = GetElem(i);
        SetElem(i, GetElem(j));
        SetElem(j, temp);
    }
    else
        cout << "下标不合法!" << endl;
}
#endif