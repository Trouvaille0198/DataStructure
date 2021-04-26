#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__
#include "../../SeqList/SeqList.h"

const int DEFAULT_SIZE = 100;
template <class T>
class MinHeap
{
private:
    SeqList<T> _elems;
    int _maxSize;
    void FilterDown(int start);
    void FilterUp(int end);

public:
    MinHeap(int maxSize = DEFAULT_SIZE);
    MinHeap(T e[], int n, int maxSize = DEFAULT_SIZE);
    ~MinHeap();
    void InsertElem(const T &e);
    void DeleteTop();
    T GetTop() const;
    bool IsEmpty() const;
    bool IsFull() const;
    int GetSize() const;
    void Clear();
    void Display() const;
};
template <class T>
void MinHeap<T>::FilterDown(int start)
// 向下调整
{
    int i = start;
    T temp = _elems.GetElem(i);
    int j = 2 * i + 1;
    while (j <= GetSize() - 1)
    {
        if (j < GetSize() - 1 && _elems.GetElem(j) > _elems.GetElem(j + 1))
            j++;
        if (temp <= _elems.GetElem(j))
            break;
        else
        {
            _elems.SetElem(i, _elems.GetElem(j));
            i = j;
            j = 2 * j + 1;
        }
    }
    _elems.SetElem(i, temp);
}
template <class T>
void MinHeap<T>::FilterUp(int end)
// 向上调整
{
    int j = end;
    T temp = _elems.GetElem(j);
    int i = (j - 1) / 2;
    while (j > 0)
    {
        if (_elems.GetElem(i) <= temp)
            break;

        else
        {
            _elems.SetElem(j, _elems.GetElem(i));
            j = i;
            i = (j - 1) / 2;
        }
        _elems.SetElem(j, temp);
    }
}
template <class T>
MinHeap<T>::MinHeap(int maxSize) : _maxSize(maxSize)
// 默认构造函数
{
    _elems = SeqList<T>(maxSize);
}

template <class T>
MinHeap<T>::MinHeap(T e[], int n, int maxSize) : _maxSize(maxSize)
{
    _elems = SeqList<T>(e, n, maxSize);

    for (int i = 0; i < n; i++)
    {
        _elems.SetElem(i, e[i]);
    }
    int i = (GetSize() - 2) / 2;
    while (i >= 0)
    {
        FilterDown(i);
        i--;
    }
}
template <class T>
MinHeap<T>::~MinHeap()
{
    Clear();
}
template <class T>
void MinHeap<T>::InsertElem(const T &e)
{
    if (IsFull())
    {
        cout << "堆已满, 别塞咯!" << endl;
        return;
    }
    _elems.InsertElem(e);
    FilterUp(GetSize() - 1);
}
template <class T>
void MinHeap<T>::DeleteTop()
{
    if (IsEmpty())
    {
        cout << "堆已空!" << endl;
        return;
    }
    _elems.SetElem(0, _elems.GetElem(GetSize() - 1));
    _elems.DeleteElemByIndex(GetSize() - 1);
    //_elems[0] = _elems[--GetSize()];
    //_elems.DeleteElemByIndex(0);
    if (GetSize() != 0)
        FilterDown(0);
}
template <class T>
T MinHeap<T>::GetTop() const
{
    if (IsEmpty())
    {
        cout << "堆已空!" << endl;
        //return;
    }
    return _elems.GetElem(0);
}
template <class T>
bool MinHeap<T>::IsEmpty() const
{
    return GetSize() == 0;
}
template <class T>
bool MinHeap<T>::IsFull() const
{
    return GetSize() == _maxSize;
}
template <class T>
int MinHeap<T>::GetSize() const
{
    return _elems.GetLength();
}
template <class T>
void MinHeap<T>::Clear()
{
    _elems.ClearList();
}
template <class T>
void MinHeap<T>::Display() const
{
    for (int i = 0; i < GetSize(); i++)
    {
        cout << _elems.GetElem(i) << " ";
    }
    cout << endl;
}
#endif