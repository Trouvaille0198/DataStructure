#include "BinSortTree.h"

int main()
{
    BinSortTree<int> t1(-1);
    int data[] = {39, 11, 8, -1, -1, 23, 17, -1, -1, 34, -1, -1, 68, 46, -1, -1, 75, 71, -1, -1, 86, -1, -1};
    t1.CreateBinTree_PreOrder_array(data, 25);
    //39 11 8 # # 23 17 # # 34 # # 68 46 # # 75 71 # # 86 # #
    cout << t1.IsBST_Recurve() << endl;
    //t1.InOrder_NoRecurve();
    int n = 60;
    t1.DisplayLarger(n);
    system("pause");
}