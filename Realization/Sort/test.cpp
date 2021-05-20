#include <bits/stdc++.h>
#include "../LinkList/DblLinkList/DblLinkList.h"
#include "ExchangeSort.h"
using namespace std;

int main()
{

    int a[10] = {4, 5, 3, 6, 2, 5, 1};
    DblLinkList<int> l1(a, 7);
    l1.Display();
    DblLinkList_BubbleSort(l1);
    l1.Display();
    system("pause");
}