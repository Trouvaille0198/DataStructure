#include "TriSparseMatrix.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    TriSparseMatrix<int> t1(50, 50, 100);
    t1.SetElem(1, 1, 50);
    cout << t1.GetElem(1, 1) << endl;
    system("pause");
}