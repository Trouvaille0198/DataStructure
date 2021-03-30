#ifndef UNION_FIND_SETS
#define UNION_FIND_SETS
#include <bits/stdc++.h>
#include "UFSetsNode.h"
using namespace std;
template <class T>
class UnionFindSets
{
protected:
    UFSetsNode<T> *_sets;
    int _size;
    int SimpleFind(T e) const;
    int CollapsingFind(T e) const;

public:
    UnionFindSets(T *elems, int n);
    ~UnionFindSets();
    T GetElem(int index) const;   //求索引指向的元素
    int GetIndex(T e) const;      //求指定元素的索引
    int Find(T e) const;          //求指定元素所在等价根元素的索引
    void Union(T a, T b);         //合并两个等价类
    void WeightedUnion(T a, T b); //合并两个等价类，结点多者作为结点少者的双亲
    void DepthUnion(T a, T b);    //合并两个等价类，深度大者作为深度小者的双亲
    void Show() const;
};

template <class T>
UnionFindSets<T>::UnionFindSets(T *elems, int n)
{
    _size = n;
    _sets = new UFSetsNode<T>[_size];
    for (int i = 0; i < _size; i++)
    {
        _sets[i]._data = elems[i];
        _sets[i]._parent = -1;
    }
}
template <class T>
UnionFindSets<T>::~UnionFindSets()
{
    delete[] _sets;
}

template <class T>
T UnionFindSets<T>::GetElem(int index) const
{
    return _sets[index]._data;
}

template <class T>
int UnionFindSets<T>::GetIndex(T e) const
{
    int index = 0;
    while (index < _size && _sets[index]._data != e)
        index++;
    if (index == _size)
        //不存在该元素，返回-1
        return -1;
    return index;
}

template <class T>
int UnionFindSets<T>::Find(T e) const
{
    int index = GetIndex(e);
    if (index != -1)
    {
        while (_sets[index]._parent > -1)
            //不断寻找e的双亲，直到找到根结点
            index = _sets[index]._parent;
        return index;
    }
    else
        return -1;
}

template <class T>
void UnionFindSets<T>::Union(T a, T b)
{
    //此时，根结点的_parent记录的是树的结点数
    int ra = Find(a);
    int rb = Find(b);

    if (ra != -1 && rb != -1 && ra != rb)
    {
        _sets[ra]._parent += _sets[rb]._parent; //个数相加
        _sets[rb]._parent = ra;                 //合并等价类，a作为b的双亲
    }
}

template <class T>
void UnionFindSets<T>::WeightedUnion(T a, T b)
{
    int ra = Find(a);
    int rb = Find(b);
    //此时，根结点的_parent记录的是树的结点数
    if (ra != -1 && rb != -1 && ra != rb)
    {
        if (_sets[ra]._parent <= _sets[rb]._parent)
        {
            _sets[ra]._parent += _sets[rb]._parent;
            _sets[rb]._parent = ra;
        }
        else
        {
            _sets[rb]._parent += _sets[ra]._parent;
            _sets[ra]._parent = rb;
        }
    }
}

template <class T>
void UnionFindSets<T>::DepthUnion(T a, T b)
{
    int ra = Find(a);
    int rb = Find(b);
    //此时，根结点的_parent记录的是树的深度
    if (ra != -1 && rb != -1 && ra != rb)
    {
        if (_sets[ra]._parent == _sets[rb]._parent)
        //若两棵树的深度相同，合并后的最小深度为原深度+1
        {
            _sets[ra]._parent--;
            _sets[rb]._parent = ra; //合并等价类，a作为b的双亲
        }
        else
        //若两棵树的深度不同，合并后的最小深度为较大者
        {
            if (_sets[ra]._parent < _sets[rb]._parent)
                _sets[rb]._parent = ra;
            else
                _sets[ra]._parent = rb;
        }
    }
}

template <class T>
void UnionFindSets<T>::Show() const
{
    cout << endl
         << "Index:  ";
    for (int i = 0; i < _size; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl
         << "Data:   ";
    for (int i = 0; i < _size; i++)
    {
        cout << setw(3) << _sets[i]._data;
    }
    cout << endl
         << "Parent: ";
    for (int i = 0; i < _size; i++)
    {
        cout << setw(3) << _sets[i]._parent;
    }
    cout << endl;
}

#endif