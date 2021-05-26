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
    cout << "排序前: ";
    l1.Display();
    DblLinkList_BubbleSort(l1);
    cout << "排序后: ";
    l1.Display();

    // 8 计数排序
    cout << "T8 计数排序" << endl;
    SeqList<int> l2(b, 7);
    cout << "排序前: ";
    l2.Display();
    CountSort(l2);
    cout << "排序后: ";
    l2.Display();

    // 9 非递归快排
    cout << "T9 非递归快排" << endl;
    SeqList<int> l3(a, 11);
    cout << "排序前: ";
    l3.Display();
    QuickSort_NoRecursive(l3);
    cout << "排序后: ";
    l3.Display();

    // 10 二路插入排序
    cout << "T10 二路插入排序" << endl;
    SeqList<int> l4(a, 11);
    cout << "排序前: ";
    l4.Display();
    BiInsertSort(l4);
    cout << "排序后: ";
    l4.Display();

    system("pause");
}
