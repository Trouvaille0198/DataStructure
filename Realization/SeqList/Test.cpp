#include "SeqList.h"
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    SeqList<int> l1(a, 6);
    l1.DisplayList();
    l1.InsertElem(2, 500);
    SeqList<int> l2;
    l2 = l1;
    l2.DisplayList();
    system("pause");
}