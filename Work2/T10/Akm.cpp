#include "../../MyOwnRealization/SeqStack/SeqStack.h"
#include <bits/stdc++.h>
using namespace std;

struct AkmType
{
    int _m, _n;
};

int Akm(int m, int n)
{
    SeqStack<AkmType> s;
    AkmType a, b; //a存储着每次循环开始时的栈顶元素；b是临时变量，用后即丢
    a._m = m;
    a._n = n;
    s.PushElem(a);
    int result = 0;

    while (!s.IsEmpty())
    {
        a = s.TopElem();
        if (a._m != 0)
        {
            if (a._n != 0) //m != 0 && n != 0
            {
                b._m = a._m;
                b._n = a._n - 1;
                s.PushElem(b);
            }
            else //m != 0 && n == 0
            {
                b = s.TopElem();
                s.PopElem();
                b._m--;
                b._n = 1;
                s.PushElem(b);
            }
        }
        else //m == 0 ，此时元素出栈计算结果，同时修改出栈后栈顶的值
        {
            result = a._n + 1;
            s.PopElem();
            if (s.IsEmpty())
                return result;
            b = s.TopElem();
            b._m--;
            b._n = result;
            s.PopElem();   //将要修改的栈顶出栈
            s.PushElem(b); //传入修改后的栈顶
        }
    }
    return result;
}

int main()
{
    int m = 2, n = 1;
    int result = Akm(m, n);
    cout << result << endl;
    system("pause");
}