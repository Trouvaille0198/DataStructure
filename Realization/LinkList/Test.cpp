#include "LinkList.h"
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    LinkList<int> l1(a, 6);
    l1.InsertElem(3, 100);
    l1.DeleteElem(3);

    l1.Display();

    system("pause");
}