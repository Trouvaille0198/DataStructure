#include <bits/stdc++.h>
#include "ExchangeSort.h"
using namespace std;

int main()
{
    int a[10] = {4, 5, 3, 6, 2, 5, 1};
    SeqList<int> l1(a, 7);
    l1.DisplayList();
    StraightInsertionSort(l1);
    l1.DisplayList();
    system("pause");
}