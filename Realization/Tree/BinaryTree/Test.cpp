#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    BinaryTree<string> t1("#");
    //BinTreeNode<string> *root = t1.GetRoot();
    //t1.SetElem(root, "A");
    //t1.InsertLeftChild(root, "B");
    //t1.InsertRightChild(root, "C");
    /* t1.PreOrder();
    cout << endl;
    t1.InOrder();
    cout << endl;
    t1.PostOrder();
    cout << endl;
    t1.PreOrder_NoRecursive();
    cout << endl;
    t1.InOrder_NoRecursive();
    cout << endl;
    t1.PostOrder_NoRecursive();
    cout << endl;
    t1.LevelOrder();
    cout << endl; */
    /*cout << t1.GetHeight() << " " << t1.GetNodeNum() << " "
         << t1.GetLeftChild(root)->_data << " " << t1.GetRightChild(root)->_data << endl;*/
    // cout << t1.GetLeftSibling(root->_rightChild)->_data << " " << t1.GetRightSibling(root->_leftChild)->_data << endl;
    t1.CreateBinTree_PreOrder(); //124##5##3#67##8##
    //  t1.InsertLeftChild(root, "B");
    //  t1.InsertRightChild(root, "C");
    //  t1.InsertLeftChild(root->_leftChild, "D");
    //  t1.LevelOrder();
    //  t1.InOrder();
    t1.PostOrder_NoRecursive();
    cout << endl;
    //cout << (root == NULL) << endl;
    BinaryTree<string> t2("#");
    string data[] = {"1", "2", "4", "#", "#", "5", "#", "#", "3", "#", "6", "7", "#", "#", "8", "#", "#"};
    t2.CreateBinTree_PreOrder_array(data, 17);
    t2.PostOrder_NoRecursive();
    system("pause");
}