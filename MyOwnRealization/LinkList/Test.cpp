#include "LinkList.h"
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    LinkList<int> l1(a, 6);

    l1.DisplayList();

    system("pause");
}