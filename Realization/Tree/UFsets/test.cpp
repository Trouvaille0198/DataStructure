#include "UFSets.h"
int main()
{
    const int n = 16;

    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int b[n] = {1, 3, 3, 1, 3, 8, 1, 3, 3, 3, 3, 14, 16, 14, 1, 1};
    int c[n] = {2, 4, 5, 7, 6, 9, 8, 10, 11, 12, 13, 15, 0, 16, 3, 14};
    UnionFindSets<int> Set1(a, n);
    UnionFindSets<int> Set2(a, n);
    UnionFindSets<int> Set3(a, n);
    cout << "Normal Union";
    for (int i = 0; i < n; i++)
    {
        Set1.Union(b[i], c[i]);
    }
    Set1.Show();
    cout << endl
         << "Weighted Union";
    for (int i = 0; i < n; i++)
    {
        Set2.WeightedUnion(b[i], c[i]);
    }
    Set2.Show();
    cout << endl
         << "Depth Union";
    for (int i = 0; i < n; i++)
    {
        Set3.DepthUnion(b[i], c[i]);
    }
    Set3.Show();

    system("pause");
}
