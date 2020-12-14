#include "SeqStack.h"
using namespace std;

int main()
{
    SeqStack<int> l1;
    l1.PushElem(1);
    l1.PushElem(2);
    l1.PushElem(3);
    l1.PushElem(4);
    l1.DisplayStack();
    SeqStack<int> l2(l1);
    SeqStack<int> l3;
    l3 = l1;
    l2.DisplayStack();
    l3.DisplayStack();

    system("pause");
}