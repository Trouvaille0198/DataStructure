#include "DblSeqStack.h"
using namespace std;

int main()
{
    DblSeqStack<int> l1(4);
    l1.PushElem(1, 1);
    l1.PushElem(2, 1);
    l1.PushElem(3, 2);
    l1.PushElem(4, 2);
    //cout << l1.IsFull() << endl;
    l1.DisplayStack();
    /* DblSeqStack<int> l2(l1);
    DblSeqStack<int> l3;
    l3 = l1;
    l2.DisplayStack();
    l3.DisplayStack(); */

    system("pause");
}