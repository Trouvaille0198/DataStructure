#include "../SeqList/SeqList.h"
#include "../LinkList/DblLinkList/DblLinkList.h"
//#include "../Tree/BinaryTree/BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

/*SeqList sort*/
// Exchange sort
template <class T>
SeqList<T> BubbleSort(SeqList<T> list)
{
    for (int i = 0; i < list.GetLength - 1; i++)
        for (int j = 0; j < list.GetLength() - 1 - i; j++)
            if (list.GetElem(i) > list.GetElem(i + 1))
                list.ExchangeElem(i, i + 1);
}

template <class T>
void QuickSortHelp(SeqList<T> &list, int start, int end)
{
    int i = start;             // 基准
    int j = end;               // 从最后开始比较
    bool pivotLocation = true; // true表示基准位置在前
    while (i < j)
    {
        if (list.GetElem(i) > list.GetElem(j))
        {
            list.ExchangeElem(i, j);
            pivotLocation = !pivotLocation;
        }
        if (pivotLocation)
            // 基准位置在前
            j--;
        else
            // 基准位置在后
            i++;
    }
    if (start < i - 1)
        QuickSortHelp(list, start, i - 1);
    if (i + 1 < end)
        QuickSortHelp(list, i + 1, end);
}

template <class T>
void QuickSort(SeqList<T> &list)
{
    QuickSortHelp(list, 0, list.GetLength() - 1);
}

//Insertion sort
template <class T>
void StraightInsertionSort(SeqList<T> &list)
{
    int j;
    for (int i = 1; i < list.GetLength(); i++) // 遍历无序区
    {
        T e = list.GetElem(i); // 取出无序区第一个元素
        for (j = i - 1; j >= 0 && list.GetElem(j) > e; j--)
            list.SetElem(j + 1, list.GetElem(j)); // 将比e大的元素后移一位
        list.SetElem(j + 1, e);                   //在j+1处插入e
    }
}

template <class T>
SeqList<T> BinaryInsertionSort(SeqList<T> list) {}

template <class T>
SeqList<T> ShellSort(SeqList<T> list) {}

// Selection sort
template <class T>
SeqList<T> SimpleSelectionSort(SeqList<T> list) {}

/*LinkList sort*/
template <class T>
void DblLinkList_BubbleSort(DblLinkList<T> &list)
{
    for (int i = 0; i < list.GetLength() - 1; i++)
    {
        for (int j = 0; j < list.GetLength() - 1 - i; j++)
        {
            if (list.GetElem(j) > list.GetElem(j + 1))
                list.ExchangeElem(j, j + 1);
        }
    }
}