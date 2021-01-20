#include "../../BinaryTree/BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

//线索二叉树结点类
template <typename T>
struct ThreadNode //结点类
{
    int _leftTag, _rightTag;                 //为0时记录子节点，为1时记录前驱或后继                                                                             //左右子树标志位
    ThreadNode<T> *_leftChild, *_rightChild; //左孩子和右孩子
    T _data;                                 //结点存储的值
    ThreadNode(T data) : _data(data),
                         _leftChild(NULL), _rightChild(NULL), _leftTag(0), _rightTag(0) {}
    ThreadNode(T data, ThreadNode<T> leftChild, ThreadNode<T> rightChild)
    {
        _data = data;
        _leftChild = leftChild;
        _leftChild = rightChild;
        _leftTag = 0;
        _rightTag = 0;
    }
};

template <typename T>
class InThreadBinTree
{
protected:
    //ThreadBinTree<T> *_tree;
    ThreadNode<T> *_root;
    T _RefValue;
    //辅助函数
    void InThread(ThreadNode<T> *root, ThreadNode<T> *&pre); //中序遍历线索化二叉树
    void CreateTree_PreOrder(ThreadNode<T> *root);           //先序遍历结果创造线索二叉树（未线索化）
    ThreadNode<T> *Transform(BinTreeNode<T> &root);          //将以root为根的二叉树转换成线索二叉树（未线索化）
    void InOrder(ThreadNode<T> *root) const;
    ThreadNode<T> *GetFirstNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetLastNode(ThreadNode<T> *cur) const;

public:
    /*构造与析构*/
    InThreadBinTree() : _root(NULL) {}
    InThreadBinTree(T RefValue) : _RefValue(RefValue), _root(NULL) {}
    InThreadBinTree(const BinaryTree<T> &s)
    {
    }
    /*建立*/
    void InThread()
    {
        ThreadNode<T> *pre = NULL;
        if (_root != NULL)
        {
            InThread(_root, pre);
            //最后pre将指向中序遍历末端结点
            pre->_rightChild = NULL;
            pre->_rightTag = 1;
        }
    }
    void CreateTree_PreOrder() { CreateTree_PreOrder(_root); }
    /*获取信息*/
    ThreadNode<T> *GetFirstNode() const { GetFirstNode(_root); }
    ThreadNode<T> *GetLastNode() const { GetLastNode(_root); }
    ThreadNode<T> *GetNextNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetPriorNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetRoot() const { return _root; };
    /*遍历*/
    void InOrder() const { InOrder(_root); }
};

template <class T>
void InThreadBinTree<T>::InThread(ThreadNode<T> *root, ThreadNode<T> *&pre)
{
    if (root != NULL)
    {
        InThread(root->_leftChild, pre);
        if (root->_leftChild == NULL)
        {
            root->_leftChild = pre;
            root->_leftTag = 1;
        }
        if (root->_rightChild == NULL)
        {
            root->_rightChild = pre;
            root->_rightTag = 1;
        }
        pre = root;
        InThread(root->_rightChild, pre);
    }
}

template <class T>
void InThreadBinTree<T>::CreateTree_PreOrder(ThreadNode<T> *root)
{
    T data;
    if (cin >> data)
    {
        if (data != _RefValue)
        {
            root = new ThreadNode<T>(data);
            cout << "新建节点完毕" << endl;
            if (root == NULL)
            {
                cout << "空间分配错误！" << endl;
                exit(1);
            }
            CreateTree_PreOrder(root->_leftChild);
            CreateTree_PreOrder(root->_rightChild);
        }
    }
}

template <class T>
ThreadNode<T> *InThreadBinTree<T>::GetFirstNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur;
    while (p->_leftTag != 1)
    {
        p = p->_leftChild;
    }
    return p;
}

template <class T>
ThreadNode<T> *InThreadBinTree<T>::GetLastNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur;
    while (p->_rightTag != 1)
    {
        p = p->_rightChild;
    }
    return p;
}

template <class T>
ThreadNode<T> *InThreadBinTree<T>::GetNextNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur->_rightChild;
    if (cur->_rightTag == 0)
    {
        return GetFirstNode(p);
    }
    return p;
}

template <class T>
ThreadNode<T> *InThreadBinTree<T>::GetPriorNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur->_leftChild;
    if (cur->_leftTag == 0)
    {
        return GetLastNode(p);
    }
    return p;
}

template <class T>
ThreadNode<T> *InThreadBinTree<T>::Transform(BinTreeNode<T> &root)
{
    if (root != NULL)
    {
        ThreadNode<T> *p = new ThreadNode<T>(root->_data, transform(root->_leftChild), transform(root->_rightChild));

        return p;
    }
    return NULL;
}

template <class T>
void InThreadBinTree<T>::InOrder(ThreadNode<T> *root) const
{
    while (root != NULL)
    {
        cout << root->_data << " ";
        root = GetNextNode(root);
    }
}