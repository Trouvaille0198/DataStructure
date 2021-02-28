#include "../../BinaryTree/BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

//线索二叉树结点类
template <typename T>
struct ThreadNode //结点类
{
    int _leftTag, _rightTag;                 //为0时记录子节点，为1时记录前驱或后继                                                                             //左右子树标志位
    ThreadNode<T> *_leftChild, *_rightChild; //左孩子(前驱)和右孩子(后继)
    //ThreadNode<T> *_parent;                  //双亲
    T _data; //结点存储的值
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
class PostThreadBinTree
{
protected:
    //ThreadBinTree<T> *_tree;
    ThreadNode<T> *_root;
    T _RefValue;
    //辅助函数
    void PostThread(ThreadNode<T> *root, ThreadNode<T> *&pre); //后序遍历对二叉树进行线索化
    void CreateTree_PreOrder(ThreadNode<T> *&root);            //用先序遍历结果创造二叉树（未线索化）
    ThreadNode<T> *Transform(BinTreeNode<T> &root);            // TODO 将以root为根的二叉树转换成线索二叉树（未线索化）
    void PostOrder(ThreadNode<T> *root) const;                 //打印后序遍历结果
    ThreadNode<T> *GetFirstNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetLastNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetParent(ThreadNode<T> *root, const ThreadNode<T> *p) const;

public:
    /*构造与析构*/
    PostThreadBinTree() : _root(NULL)
    {
    }
    PostThreadBinTree(T RefValue) : _RefValue(RefValue), _root(NULL) {}
    PostThreadBinTree(const BinaryTree<T> &s)
    {
    }
    /*建立*/
    void PostThread()
    //后序遍历对创建好的普通二叉树进行后序线索化
    {
        ThreadNode<T> *pre = NULL;
        if (_root != NULL)
        {
            PostThread(_root, pre);
            //最后pre将指向后序遍历末端结点
            //pre->_rightChild = NULL; //末端节点设为空
            //pre->_rightTag = 1;
        }
        //ThreadNode<T> *first = GetFirstNode(_root);
        //first->_leftChild = NULL;
        //first->_rightTag = 1;
    }
    void CreateTree_PreOrder() { CreateTree_PreOrder(_root); }
    /*获取信息*/
    ThreadNode<T> *GetFirstNode() const { GetFirstNode(_root); }
    ThreadNode<T> *GetLastNode() const { GetLastNode(_root); }
    ThreadNode<T> *GetNextNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetPriorNode(ThreadNode<T> *cur) const;
    ThreadNode<T> *GetRoot() const { return _root; };
    ThreadNode<T> *GetParent(const ThreadNode<T> *p) const { return GetParent(_root, p); }
    /*遍历*/
    void PostOrder() const { PostOrder(_root); }
};

template <class T>
void PostThreadBinTree<T>::PostThread(ThreadNode<T> *root, ThreadNode<T> *&pre)
//后序遍历对二叉树进行线索化
{
    if (root != NULL)
    {
        PostThread(root->_leftChild, pre);
        PostThread(root->_rightChild, pre);
        if (root->_leftChild == NULL)
        {
            root->_leftChild = pre;
            root->_leftTag = 1;
        }
        if (pre != NULL && pre->_rightChild == NULL)
        {
            pre->_rightChild = root;
            pre->_rightTag = 1;
        }
        pre = root; //用前驱记住当前的结点
    }
}

template <class T>
void PostThreadBinTree<T>::CreateTree_PreOrder(ThreadNode<T> *&root)
//输入先序遍历结果，创造二叉树（未线索化）
{
    T data;
    cout << "input data: " << endl;
    if (cin >> data)
    {
        if (data != _RefValue)
        {
            root = new ThreadNode<T>(data);
            // cout << "新建节点完毕" << endl;
            if (root == NULL)
            {
                cout << "空间分配错误！" << endl;
                exit(1);
            }
            CreateTree_PreOrder(root->_leftChild);
            CreateTree_PreOrder(root->_rightChild);
        }
        else
        {
            root = NULL;
        }
    }
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::GetFirstNode(ThreadNode<T> *cur) const
//寻找以cur为根的树在后序下的第一个节点
{
    ThreadNode<T> *p = cur;
    while (p->_leftTag == 0 || p->_rightTag == 0)
    {
        if (p->_leftTag == 0)
            p = p->_leftChild;
        else
            p = p->_rightChild;
    }
    return p;
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::GetLastNode(ThreadNode<T> *cur) const
//寻找以cur为根的树在后序下的最后一个节点
{
    return cur;
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::GetNextNode(ThreadNode<T> *cur) const
//寻找指定节点的后继
{
    if (cur == _root)
    {
        return NULL;
    }
    //ThreadNode<T> *p = cur;
    if (cur->_rightTag == 0)
    //若cur有右孩子
    {
        ThreadNode<T> *parent = GetParent(_root, cur);
        if (parent->_rightChild == cur || parent->_rightTag == 1)
        {
            return parent;
        }
        ThreadNode<T> *p = parent->_rightChild;
        while (p->_leftTag == 0 || p->_rightTag == 0)
        {
            if (p->_leftTag == 0)
                p = p->_leftChild;
            else
                p = p->_rightChild;
        }
        return p;
    }
    else
        //若cur有后继，则直接返回后继
        return cur->_rightChild;
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::GetPriorNode(ThreadNode<T> *cur) const
//寻找指定节点的前驱
//TODO
{
    ThreadNode<T> *p = cur->_leftChild;
    if (cur->_leftTag == 0)
    {
        return GetLastNode(p);
    }
    return p;
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::Transform(BinTreeNode<T> &root)
// TODO
//将以root为根的普通二叉树转换成线索二叉树（未线索化）
{
    if (root != NULL)
    {
        ThreadNode<T> *p = new ThreadNode<T>(root->_data, Transform(root->_leftChild), Transform(root->_rightChild));

        return p;
    }
    return NULL;
}

template <class T>
void PostThreadBinTree<T>::PostOrder(ThreadNode<T> *root) const
//打印后序遍历结果
{
    root = GetFirstNode(root);
    while (root != NULL)
    {
        cout << root->_data << " ";
        root = GetNextNode(root);
    }
    cout << endl;
}

template <class T>
ThreadNode<T> *PostThreadBinTree<T>::GetParent(ThreadNode<T> *root, const ThreadNode<T> *p) const
//从root开始搜索p的父节点
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->_leftChild == p || root->_rightChild == p) //如果找到，返回父节点root
    {
        return root;
    }
    if (GetParent(root->_leftChild, p) == p) //递归在左子树中搜索
    {
        return GetParent(root->_leftChild, p);
    }
    else //递归右子树中搜索
    {
        return GetParent(root->_rightChild, p);
    }
}