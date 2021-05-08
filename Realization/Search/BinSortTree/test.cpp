#include "BinSortTree.h"

int main()
{
    BinSortTree<string> t1("#");
    t1.CreateBinTree_PreOrder(); //124##5##3#67##8##
    //39 11 8 # # 23 17 # # 34 # # 68 46 # # 75 71 # # 86 # #
    //39 11 # # 68 # #
    cout << t1.IsBST_Recurve() << endl;
    system("pause");
}