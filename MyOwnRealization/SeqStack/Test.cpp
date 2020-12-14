#include "SeqStack.h"
using namespace std;

int main()
{
    SeqStack<int> l1;
    l1.PushElem(1);
    l1.PushElem(2);
    l1.PushElem(3);
    l1.PushElem(4);
    cout << l1.TopElem() << endl;
    l1.DisplayStack();

    system("pause");
}