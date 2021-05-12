#include "BinAVLTreeNode.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinAVLTree
{
protected:
    BinAVLTreeNode<T> *_root;
    T _refValue;
    // 辅助函数
    void CreateBinTree_PreOrder_array(BinAVLTreeNode<T> *&root,
                                      T *data, int &index, int length); // 传入先序遍历数组创建二叉树
    int GetNodeNum(const BinAVLTreeNode<T> *p) const;                   // 获取p结点为根的子树节点个数
    void GetLsize(BinAVLTreeNode<T> *p);                                // 获取p结点左子树节点个数+1
    BinAVLTreeNode<T> *LocateNode(BinAVLTreeNode<T> *p, int k);
    void PreOrder(BinAVLTreeNode<T> *&root);
    void InOrder(BinAVLTreeNode<T> *&root);

public:
    BinAVLTree(T refValue) : _refValue(refValue) { _root = new BinAVLTreeNode<T>; }
    void GetLsize() { GetLsize(_root); }
    void CreateBinTree_PreOrder_array(T *data, int length)
    {
        int index = 0;
        CreateBinTree_PreOrder_array(_root, data, index, length);
        GetLsize();
    }
    BinAVLTreeNode<T> *LocateNode(int k) { return LocateNode(_root, k); } // 查找第k小的结点
    void PreOrder() { PreOrder(_root); }
    void InOrder() { InOrder(_root); }
};
template <class T>
int BinAVLTree<T>::GetNodeNum(const BinAVLTreeNode<T> *p) const
{
    if (!p)
        return 0;
    return 1 + GetNodeNum(p->_leftChild) + GetNodeNum(p->_rightChild);
}
template <class T>
void BinAVLTree<T>::GetLsize(BinAVLTreeNode<T> *p)
{
    if (!p)
        return;
    p->_lsize = 1 + GetNodeNum(p->_leftChild);
    GetLsize(p->_leftChild);
    GetLsize(p->_rightChild);
}

template <class T>
void BinAVLTree<T>::CreateBinTree_PreOrder_array(BinAVLTreeNode<T> *&root,
                                                 T *data, int &index, int length)
{
    if (data[index] != _refValue && index < length)
    {
        root = new BinAVLTreeNode<T>(data[index]);
        CreateBinTree_PreOrder_array(root->_leftChild, data, ++index, length);  //递归创建左子树
        CreateBinTree_PreOrder_array(root->_rightChild, data, ++index, length); //递归创建右子树
    }
    else
        root = NULL;
}

template <class T>
BinAVLTreeNode<T> *BinAVLTree<T>::LocateNode(BinAVLTreeNode<T> *p, int k)
{
    if (!p)
        return NULL;
    if (p->_lsize == k)
        return p;
    else if (p->_lsize > k)
        return LocateNode(p->_leftChild, k);
    else
        return LocateNode(p->_rightChild, k - p->_lsize);
}

template <class T>
void BinAVLTree<T>::PreOrder(BinAVLTreeNode<T> *&root)
{
    if (root != NULL)
    {
        cout << root->_data << " ";
        PreOrder(root->_leftChild);
        PreOrder(root->_rightChild);
    }
}

template <class T>
void BinAVLTree<T>::InOrder(BinAVLTreeNode<T> *&root)
{
    if (root != NULL)
    {
        InOrder(root->_leftChild);
        cout << root->_data << " ";
        InOrder(root->_rightChild);
    }
}