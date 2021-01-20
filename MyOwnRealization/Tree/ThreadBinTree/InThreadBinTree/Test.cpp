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
    //cout << "Step1" << endl;
    //itbt1.InThread();
    //cout << "Step2" << endl;
    //itbt1.InOrder();
    //cout << "Step3" << endl;
    cout << (root == NULL) << endl;
    system("pause");
}