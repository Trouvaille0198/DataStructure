#include "../SeqList/SeqList.h"
#include "../LinkList/DblLinkList/DblLinkList.h"
#include "../SeqStack/SeqStack.h"
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
void CountSort(SeqList<T> &list)
{
    // SeqList<T> countList(list.GetLength());
    // SeqList<T> sortedList(list.GetLength());
    // for (int i = 0; i < list.GetLength()-1;i++)
    //     for (int j = i + 1; j < list.GetLength();j++){
    //         if(list.GetElem(i)<list.GetElem(j))

    //     }
    int count = 0;
    SeqList<T> sortedList(list.GetLength());
    for (int i = 0; i < list.GetLength(); i++)
        sortedList.InsertElem(0);
    for (int i = 0; i < list.GetLength(); i++)
    {
        for (int j = 0; j < list.GetLength(); j++)
        {
            if (i == j)
                continue;
            else if (list.GetElem(j) < list.GetElem(i))
                count++;
        }
        sortedList.SetElem(count, list.GetElem(i)); // 将关键字保存在以计数值为索引的位置
        count = 0;
    }
    list = sortedList;
}

template <class T>
void QuickSort(SeqList<T> &list)
{
    QuickSortHelp(list, 0, list.GetLength() - 1);
}

template <class T>
int OneQuickSort(SeqList<T> &list, int start, int end)
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
    return i; //返回基准下标
}

template <class T>
void QuickSort_NoRecursive(SeqList<T> &list)
{
    int start, end, pivot;
    SeqStack<T> s;
    s.PushElem(list.GetElem(0));
    s.PushElem(list.GetElem(list.GetLength() - 1)); // 头尾入栈
    while (!s.IsEmpty())
    {
        start = s.TopElem();
        s.PopElem();
        end = s.TopElem();
        s.PopElem();
        while (end - start >= 3)
        // 若长度大于三
        {
            pivot = OneQuickSort(list, start, end); // 来一趟
            // 比较左右子串的长短，短者先排，长者入栈
            if (pivot - start < end - pivot)
            {
                s.PushElem(pivot + 1);
                s.PushElem(end);
                end = pivot - 1;
            }
            else
            {
                s.PushElem(start);
                s.PushElem(pivot - 1);
                start = pivot + 1;
            }
        }
        if (end - start == 2)
        // 长度等于三，暴力交换
        {
            if (list.GetElem(start) > list.GetElem(start + 1))
                list.ExchangeElem(start, start + 1);
            if (list.GetElem(start) > list.GetElem(end))
                list.ExchangeElem(start, end);
            if (list.GetElem(start + 1) > list.GetElem(end))
                list.ExchangeElem(start + 1, end);
        }
        else if (end - start == 1)
        // 长度等于二，暴力交换
        {
            if (list.GetElem(start) > list.GetElem(end))
                list.ExchangeElem(start, end);
        }
    }
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