#ifndef __MAX_HEAP_H__
#define __MAX_HEAP_H__
#include "../../SeqList/SeqList.h"

const int DEFAULT_SIZE = 100;
template <class T>
class MaxHeap
{
private:
    SeqList<T> _elems;
    int _maxSize;
    void FilterDown(int start);
    void FilterUp(int end);

public:
    MaxHeap(int maxSize = DEFAULT_SIZE);
    MaxHeap(T e[], int n, int maxSize = DEFAULT_SIZE);
    ~MaxHeap();
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
void MaxHeap<T>::FilterDown(int start)
// 向下调整
{
    int i = start;
    T temp = _elems.GetElem(i);
    int j = 2 * i + 1;
    while (j <= GetSize() - 1)
    {
        if (j < GetSize() - 1 && _elems.GetElem(j) < _elems.GetElem(j + 1))
            j++;
        if (temp >= _elems.GetElem(j))
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
void MaxHeap<T>::FilterUp(int end)
// 向上调整
{
    int j = end;
    T temp = _elems.GetElem(j);
    int i = (j - 1) / 2;
    while (j > 0)
    {
        if (_elems.GetElem(i) >= temp)
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
MaxHeap<T>::MaxHeap(int maxSize) : _maxSize(maxSize)
// 默认构造函数
{
    _elems = SeqList<T>(maxSize);
}
template <class T>
MaxHeap<T>::MaxHeap(T e[], int n, int maxSize) : _maxSize(maxSize)
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
MaxHeap<T>::~MaxHeap()
{
    Clear();
}
template <class T>
void MaxHeap<T>::InsertElem(const T &e)
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
void MaxHeap<T>::DeleteTop()
{
    if (IsEmpty())
    {
        cout << "堆已空!" << endl;
        return;
    }
    _elems.SetElem(0, _elems.GetElem(GetSize() - 1));
    _elems.DeleteElemByIndex(GetSize() - 1);
    if (GetSize() != 0)
        FilterDown(0);
}
template <class T>
T MaxHeap<T>::GetTop() const
{
    if (IsEmpty())
    {
        cout << "堆已空!" << endl;
        //return NULL;
    }
    return _elems.GetElem(0);
}
template <class T>
bool MaxHeap<T>::IsEmpty() const
{
    return GetSize() == 0;
}
template <class T>
bool MaxHeap<T>::IsFull() const
{
    return GetSize() == _maxSize;
}
template <class T>
int MaxHeap<T>::GetSize() const
{
    return _elems.GetLength();
}
template <class T>
void MaxHeap<T>::Clear()
{
    _elems.ClearList();
}
template <class T>
void MaxHeap<T>::Display() const
{
    for (int i = 0; i < GetSize(); i++)
    {
        cout << _elems.GetElem(i) << " ";
    }
    cout << endl;
}
#endif