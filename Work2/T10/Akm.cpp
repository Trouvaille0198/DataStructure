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
    AkmType w, e;
    w._m = m;
    w._n = n;
    int result;
    s.PushElem(w);

    do
    {
        e = s.TopElem();
        while (e._m != 0)
        {
            while (e._n != 0) //m != 0 && n != 0时，将其化为m != 0, m == 0
            {
                w._n--;
                s.PushElem(w);
                e = s.TopElem();
            }
            //m != 0,m == 0时，将其化为m = m - 1, n=1
            w = s.TopElem();
            s.PopElem();
            w._m--;
            w._n = 1;
            s.PushElem(w);
            e = s.TopElem();
        }
        w = s.TopElem();
        s.PopElem();
        result = ++w._n;
        if (!s.IsEmpty()) //若栈非空，改栈顶为(m-1, v)
        {
            w = s.TopElem();
            s.PopElem();
            w._m--;
            w._n = result;
            s.PushElem(w);
        }
    } while (!s.IsEmpty());

    return result;
}

int main()
{
    system("pause");
}