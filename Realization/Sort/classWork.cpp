#include <bits/stdc++.h>
#include "../LinkList/DblLinkList/DblLinkList.h"
#include "ExchangeSort.h"
using namespace std;

int main()
{
    int a[11] = {4, 5, 3, 6, 2, 5, 1, 12, 10, 9, 8};
    int b[10] = {4, 5, 3, 6, 2, 1, 8};

    //5 双向链表冒泡
    cout << "T5 双向链表冒泡" << endl;
    DblLinkList<int> l1(a, 11);
    l1.Display();
    DblLinkList_BubbleSort(l1);
    l1.Display();

    // 8 计数排序
    cout << "T8 计数排序" << endl;
    SeqList<int> l2(b, 7);
    l2.DisplayList();
    CountSort(l2);
    l2.DisplayList();

    // 9 非递归快排
    cout << "T9 非递归快排" << endl;
    SeqList<int> l3(a, 11);
    l3.DisplayList();
    QuickSort_NoRecursive(l3);
    l3.DisplayList();

    // 10 二路插入排序
    cout << "T10 二路插入排序" << endl;
    SeqList<int> l4(a, 11);
    l4.DisplayList();
    BiInsertSort(l4);
    l4.DisplayList();

    system("pause");
}
