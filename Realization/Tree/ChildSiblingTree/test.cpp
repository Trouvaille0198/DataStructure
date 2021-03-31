#include <bits/stdc++.h>
#include "ChildSiblingTree.h"
using namespace std;
int main()
{
    char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int parents[] = {-1, 0, 0, 0, 0, 1, 1, 3, 5};
    int n = 9;
    ChildSiblingTree<char> t(items, parents, n);
    //        A
    //   B    C    D   E
    // F  G      H
    //          I
    cout << "树的度为：" << t.GetDegree() << endl;
    cout << "树的高度为：" << t.GetHeight() << endl;
    system("pause");
}