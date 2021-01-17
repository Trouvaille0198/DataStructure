#include "../../../LinkQueue/LinkQueue.h"
#include "../../../LinkStack/LinkStack.h"
#include <bits/stdc++.h>
using namespace std;

//线索二叉树结点类
template <typename T>
struct ThreadNode //结点类
{
    int _leftTag, _rightTag;                 //为0时记录子节点，为1时记录前驱或后继                                                                             //左右子树标志位
    ThreadNode<T> *_leftChild, *_rightChild; //左孩子和右孩子
    T _data;                                 //结点存储的值
    ThreadNode(const T data) : _data(data),
                               _leftChild(NULL), _rightChild(NULL), _leftTag(0), _rightTag(0) {}
};

template <typename T>
class ThreadBinTree
{
private:
    ThreadNode<T> *_root;

public:
    ThreadBinTree() : _root(NULL) {}
};

template <typename T>
class InThreadBinTree
{
protected:
    //ThreadBinTree<T> *_tree;
    ThreadNode<T> *_root;
    T _RefValue;
    //辅助函数
    void InThread(ThreadNode<T> *root, ThreadNode<T> *pre); //中序遍历线索化二叉树
    void CreateTree_PreOrder(ThreadNode<T> *root);

public:
    /*构造与析构*/
    InThreadBinTree() : _root(NULL) {}
    InThreadBinTree(T RefValue) : _RefValue(RefValue), _root(NULL) {}
    /*建立*/
    void InThread()
    {
        ThreadNode<T> *pre = NULL;
        if (_root != NULL)
        {
            InThread(_root, pre);
            //最后pre将指向中序遍历末端结点
            pre->_rightChild == NULL;
            pre->_rightTag = 1;
        }
    }
    void CreateTree_PreOrder() { CreateTree_PreOrder(_root); }
    /*获取信息*/
    ThreadNode<T> GetFirstNode() const;
    ThreadNode<T> GetLastNode() const;
    ThreadNode<T> GetNextNode(ThreadNode<T> *cur) const;
    ThreadNode<T> GetPriorNode(ThreadNode<T> *cur) const;
};

template <class T>
void InThreadBinTree<T>::InThread(ThreadNode<T> *root, ThreadNode<T> *pre)
{
    if (root != NULL)
    {
        InThread(root->_leftChild);
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
        InThread(root->_rightChild);
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
            CreateTree_PreOrder(root->_leftChild);
            CreateTree_PreOrder(root->_rightChild);
        }
        else
        {
            root == NULL;
        }
    }
}

template <class T>
ThreadNode<T> InThreadBinTree<T>::GetFirstNode() const
{
    ThreadNode<T> *p = _root;
    while (p->_leftTag != 1)
    {
        p = p->_leftChild;
    }
    return p;
}

template <class T>
ThreadNode<T> InThreadBinTree<T>::GetLastNode() const
{
    ThreadNode<T> *p = _root;
    while (p->_rightTag != 1)
    {
        p = p->_rightChild;
    }
    return p;
}

template <class T>
ThreadNode<T> InThreadBinTree<T>::GetNextNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur->_rightChild;
    if (cur->_rightTag == 0)
    {
        return GetFirstNode(p);
    }
    return p;
}

template <class T>
ThreadNode<T> InThreadBinTree<T>::GetPriorNode(ThreadNode<T> *cur) const
{
    ThreadNode<T> *p = cur->_leftChild;
    if (cur->_leftTag == 0)
    {
        return GetLastNode(p);
    }
    return p;
}