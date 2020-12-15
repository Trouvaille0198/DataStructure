#include "LinkStack.h"

int main()
{
    LinkStack<int> l1;
    l1.PushElem(1);
    l1.PushElem(2);
    l1.PushElem(3);
    l1.PushElem(4);
    l1.DisplayStack();

    system("pause");
}