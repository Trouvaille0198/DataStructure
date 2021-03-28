#include "InThreadBinTree.h"
using namespace std;

int main()
{
    /* BinaryTree<string> bt1("#");
    BinTreeNode<string> *root = bt1.GetRoot();
    bt1.SetElem(root, "A");
    bt1.InsertLeftChild(root, "B");
    bt1.InsertRightChild(root, "C");
    bt1.InsertLeftChild(root->_leftChild, "D"); */
    //bt1.InOrder();

    InThreadBinTree<string> itbt1("#");
    itbt1.CreateTree_PreOrder();
    ThreadNode<string> *root = itbt1.GetRoot();
    cout << "Step1 中序线索化" << endl;
    itbt1.InThread(); //中序线索化
    cout << "Step2 打印中序遍历结果" << endl;
    itbt1.InOrder(); //打印中序遍历结果
    // cout << "Step3" << endl;
    system("pause");
}