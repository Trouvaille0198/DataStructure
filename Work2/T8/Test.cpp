#include <bits/stdc++.h>
#include "../../MyOwnRealization/SeqStack/SeqStack.h"
using namespace std;

void Test()
//倒加函数
{
    int sum = 0;
    SeqStack<int> s;
    int x;
    do
    {
        cin >> x;
        s.PushElem(x);
    } while (x != 0);
    while (!s.IsEmpty())
    {
        x = s.TopElem();
        s.PopElem();
        sum += x;
        cout << "The sum is: " << sum << endl;
    }
}

int main()
{
    Test();
    system("pause");
}