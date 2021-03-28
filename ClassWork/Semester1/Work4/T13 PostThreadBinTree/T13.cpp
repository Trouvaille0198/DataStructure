#include "../../MyOwnRealization/Tree/ThreadBinTree/PostThreadBinTree/PostThreadBinTree.h"
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

    PostThreadBinTree<string> ptbt1("#");
    ptbt1.CreateTree_PreOrder(); // 124##5##3#67##8##
    //        1
    //     2     3
    //   4   5      6
    //            7   8

    ptbt1.PostThread(); //后序线索化
    cout << "打印后序遍历结果" << endl;
    ptbt1.PostOrder(); //打印后序遍历结果
    string p;
    cout << "请输入节点: ";
    while (cin >> p && p != "stop")
    {
        ThreadNode<string> *targetNode = ptbt1.GetNodeByName(p);
        //cout << targetNode->GetData() << endl;
        if (targetNode != NULL)
        {
            targetNode = ptbt1.GetNextNode(targetNode);
            if (targetNode != NULL)
            {
                cout << "此节点的后继为" << targetNode->GetData() << endl;
            }
            else
                cout << "此节点无后继" << endl;
        }
        else
        {
            cout << "无此节点" << endl;
        }
        cout << "请输入节点: ";
    }
    system("pause");
}