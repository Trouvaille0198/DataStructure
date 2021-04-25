#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__
#include "../../SeqList/SeqList.h"

const int DEFAULT_SIZE = 100;
template <class T>
class MinimumHeap
{
private:
    SeqList<T> _elems;
    int _maxSize;
    void FilterDown(int start);
    void FilterUp(int end);

public:
    MinimumHeap(int maxsize = DEFAULT_SIZE);
    MinimumHeap(T e[], int n, int maxsize = DEFAULT_SIZE);
    ~MinimumHeap();
    Status InsertElem(const T &e);
    Status DeleteTop(T &e);
    Status GetTop(T &e) const;
    bool IsEmpty() const;
    bool IsFull() const;
    int GetSize() const;
    void Clear();
    void Traverse(void (*Visit)(const T &)) const;
};
template <class T>
void MinimumHeap<T>::FilterDown(int start)
{
    int i = start;
    T temp = elems_[i];
    int j = 2 * i + 1;
    while (j <= size_ - 1)
    {
        if (j < size_ - 1 and elems_[j] > elems_[j + 1])
        {
            j++;
        }
        if (temp <= elems_[j])
        {
            break;
        }
        else
        {
            elems_[i] = elems_[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    elems_[i] = temp;
}
template <class T>
void MinimumHeap<T>::FilterUp(int end)
{
    int j = end;
    T temp = elems_[j];
    int i = (j - 1) / 2;
    while (j > 0)
    {
        if (elems_[i] <= temp)
        {
            break;
        }
        else
        {
            elems_[j] = elems_[i];
            j = i;
            i = (j - 1) / 2;
        }
        elems_[j] = temp;
    }
}
template <class T>
MinimumHeap<T>::MinimumHeap(int maxsize) : size_(0), maxSize_(maxsize)
{
    elems_ = new T[maxsize];
    assert(elems_);
}
template <class T>
MinimumHeap<T>::MinimumHeap(T e[], int n, int maxsize) : size_(n), maxSize_(maxsize)
{
    elems_ = new T[maxsize];
    assert(elems_);
    for (int i = 0; i < n; i++)
    {
        elems_[i] = e[i];
    }
    int i = (size_ - 2) / 2;
    while (i >= 0)
    {
        FilterDown(i);
        i--;
    }
}
template <class T>
MinimumHeap<T>::~MinimumHeap()
{
    delete[] elems_;
}
template <class T>
Status MinimumHeap<T>::InsertElem(const T &e)
{
    if (IsFull())
    {
        return OVER_FLOW;
    }
    elems_[size_] = e;
    FilterUp(size_);
    size_++;
    return SUCCESS;
}
template <class T>
Status MinimumHeap<T>::DeleteTop(T &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[0];
    elems_[0] = elems_[--size_];
    FilterDown(0);
    return SUCCESS;
}
template <class T>
Status MinimumHeap<T>::GetTop(T &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[0];
    return SUCCESS;
}
template <class T>
bool MinimumHeap<T>::IsEmpty() const
{
    return size_ == 0;
}
template <class T>
bool MinimumHeap<T>::IsFull() const
{
    return size_ == maxSize_;
}
template <class T>
int MinimumHeap<T>::GetSize() const
{
    return size_;
}
template <class T>
void MinimumHeap<T>::Clear()
{
    size_ = 0;
}
template <class T>
void MinimumHeap<T>::Traverse(void (*Visit)(const T &)) const
{
    for (int i = 0; i < size_; i++)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}
#endif