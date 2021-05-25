#include "BinSortTree.h"
using namespace std;
int main()
{
    BinSortTree<int> t1(-1);
    int data[] = {39, 11, 8, -1, -1, 23, 17, -1, -1, 34, -1, -1, 68, 46, -1, -1, 75, 71, -1, -1, 86, -1, -1};
    t1.CreateBinTree_PreOrder_array(data, 25);
    //39 11 8 # # 23 17 # # 34 # # 68 46 # # 75 71 # # 86 # #
    cout << "中序遍历输出树节点" << endl;
    t1.InOrder();
    cout << endl;
    string isBST = t1.IsBST_Recursive() ? "是" : "不是";
    cout << "这棵树" << isBST << "二叉排序树" << endl;

    int n = 60;
    cout << "大于 " << n << " 的结点有: ";
    t1.DisplayLarger(n);

    int x1 = 11, x2 = 12;
    cout << "试图查询 " << x1 << ", " << x2 << endl;
    t1.SearchOrInsert(x1);
    t1.SearchOrInsert(x2);

    cout << "中序遍历输出树节点" << endl;
    t1.InOrder();
    cout << endl;
    system("pause");
}