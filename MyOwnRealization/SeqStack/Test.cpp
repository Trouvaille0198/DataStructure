#include "SeqStack.h"
using namespace std;

int main()
{
    SeqStack<int> l1;
    l1.PushElem(1);
    cout << l1.IsEmpty() << endl;
    l1.PushElem(2);
    l1.PushElem(3);
    l1.PushElem(4);
    l1.DisplayStack();

    system("pause");
}