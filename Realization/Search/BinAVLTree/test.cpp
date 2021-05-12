#include "BinAVLTree.h"
using namespace std;

int main()
{
    BinAVLTree<int> t1(-1);
    int data[] = {39, 11, 8, -1, -1, 23, -1, -1, 68, 46, -1, -1, 75, 71, -1, -1, -1};
    t1.CreateBinTree_PreOrder_array(data, 17);
    int n = 8;
    BinAVLTreeNode<int> *p = t1.LocateNode(n);
    if (p)
        cout << "第" << n << "小的结点是: " << p->_data << endl;
    else
        cout << "找不到结点!" << endl;
    system("pause");
}