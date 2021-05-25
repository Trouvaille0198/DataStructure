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
    int n = list.GetLength;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (list[i] > list[i + 1])
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
        if (list[i] > list[j])
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
    //         if(list[i]<list[j])

    //     }
    int count = 0;
    int n = list.GetLength();
    SeqList<T> sortedList(n);
    for (int i = 0; i < n; i++)
        sortedList.InsertElem(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if (list[j] < list[i])
                count++;
        }
        sortedList[count] = list[i]; // 将关键字保存在以计数值为索引的位置
        //sortedList.SetElem(count, list[i]);
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
        if (list[i] > list[j])
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
    s.PushElem(0);                    // 头入栈
    s.PushElem(list.GetLength() - 1); // 尾入栈

    while (!s.IsEmpty())
    {
        end = s.TopElem();
        s.PopElem();
        start = s.TopElem();
        s.PopElem();

        while (end - start >= 3)
        // 若长度大于三
        {
            // 来一趟
            int i = start;             // 基准
            int j = end;               // 从最后开始比较
            bool pivotLocation = true; // true表示基准位置在前
            while (i < j)
            {
                if (list[i] > list[j])
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
            pivot = i;
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
            if (list[start] > list[start + 1])
                list.ExchangeElem(start, start + 1);
            if (list[start] > list[end])
                list.ExchangeElem(start, end);
            if (list[start + 1] > list[end])
                list.ExchangeElem(start + 1, end);
        }
        else if (end - start == 1)
        // 长度等于二，暴力交换
        {
            if (list[start] > list[end])
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
        T e = list[i]; // 取出无序区第一个元素
        for (j = i - 1; j >= 0 && list[j] > e; j--)
            list[j + 1] = list[j]; // 将比e大的元素后移一位
        list[j + 1] = e;           //在j+1处插入e
    }
}

template <class T>
void BiInsertSort(SeqList<T> &list)
// 二路插排，运用循环表思想，以0下标为始，较小序列向前延伸，较大序列向后延伸
{
    int n = list.GetLength();
    SeqList<T> d(n);
    int start = 0; // 指向第一个元素
    int end = 0;   // 指向最后一个元素
    int i, j;      // 起指示作用
    d[0] = list[0];
    for (i = 1; i < n; i++)
    {
        if (list[i] > d[0])
        // 插入后半部分
        {
            j = end;
            while (j > 0 && list[i] < d[j])
            // 从最大元素开始比较, 每个元素依次向右移动
            {
                d[j + 1] = d[j];
                j--;
            }
            d[j + 1] = list[i];
            end++;
        }
        else
        // 插入前半部分
        {
            if (start == 0)
            // 初始化
            {
                d[n - 1] = list[i];
                start = n - 1;
            }
            else
            // 从最大元素开始比较, 每个元素依次向左回退
            {
                j = start;
                while (j < n && list[i] > d[j])
                {
                    d[j - 1] = d[j];
                    j++;
                }
                d[j - 1] = list[i];
                start--;
            }
        }
    }
    list[0] = d[start];
    for (i = (start + 1) % n, j = 1; j < n; i = (i + 1) % n, j++)
        list[j] = d[i]; // 覆盖原数组
}

template <class T>
SeqList<T> BinaryInsertionSort(SeqList<T> list)
{
}

template <class T>
SeqList<T> ShellSort(SeqList<T> list) {}

// Selection sort
template <class T>
SeqList<T> SimpleSelectionSort(SeqList<T> list) {}

/*LinkList sort*/
template <class T>
void DblLinkList_BubbleSort(DblLinkList<T> &list)
{
    int n = list.GetLength();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (list.GetElem(j) > list.GetElem(j + 1))
                list.ExchangeElem(j, j + 1);
        }
    }
}