#include "TriSparseMatrix.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    TriSparseMatrix<int> t1(50, 50, 100);
    TriSparseMatrix<int> t2(50, 50, 100);
    /* t1.SetElem(1, 1, 50);
    t1.SetElem(1, 2, 51);
    cout << t1.GetElem(1, 1) << ", " << t1.GetElem(1, 2) << endl;
    t1.SetElem(1, 1, 0);
    t1.SetElem(1, 2, 55);
    cout << t1.GetElem(1, 1) << ", " << t1.GetElem(1, 2) << endl;
    cout << t1.GetNum() << endl; */
    t1.SetElem(0, 0, 5);
    t1.SetElem(0, 2, 5);
    t1.SetElem(1, 2, 5);
    t1.SetElem(3, 4, 5);
    t1.SetElem(9, 9, 100);

    t2.SetElem(0, 0, 6);
    t2.SetElem(0, 4, 6);
    t2.SetElem(2, 4, 6);
    t2.SetElem(3, 4, -5);
    TriSparseMatrix<int> tt(50, 50, 100);
    tt = t1 + t2;
    tt.Display();
    cout << tt.GetNum() << endl;
    system("pause");
}