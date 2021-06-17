//求最大宽度
#include "../../MyOwnRealization/Tree/BinaryTree/BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    BinaryTree<string> t1("#");
    BinTreeNode<string> *root = t1.GetRoot();
    t1.CreateBinTree_PreOrder(); //124##5##3#67##8##
    //        1
    //     2     3
    //   4   5      6
    //            7   8
    t1.LevelOrder();
    //t1.InOrder();
    cout
        << endl
        << "最大宽度: "
        << t1.GetmaxWidth() << endl;
    system("pause");
}