#ifndef CHILD_SIBLING_TREE
#define CHILD_SIBLING_TREE
#include "../../LinkQueue/LinkQueue.h"
#include "CSTreeNode.h"

template <class T>
struct ChildSiblingTree
{
protected:
    CSTreeNode<T> *_root;
    //辅助函数
    CSTreeNode<T> *CreateTree(T nodes[], int parents[], int n, int rootIndex);
    void Destroy(CSTreeNode<T> *&r);
    int GetHeight(CSTreeNode<T> *r) const;
    int GetNodeDegree(CSTreeNode<T> *r) const;             //求单个结点r的度
    int GetDegree(CSTreeNode<T> *r) const;                 //求以r为根节点的树的度
    CSTreeNode<T> *GetFirstChild(CSTreeNode<T> *r) const;  //求结点r的第一个孩子
    CSTreeNode<T> *GetNextSibling(CSTreeNode<T> *r) const; //求结点r的下一个兄弟

public:
    ChildSiblingTree() { _root = NULL; }               //默认构造函数
    ChildSiblingTree(T nodes[], int parents[], int n); //构造函数
    virtual ~ChildSiblingTree() { Destroy(_root); }    //析构函数
    CSTreeNode<T> *GetRoot() const;                    //得到树的根结点
    bool IsEmpty() const;                              //判断树是否为空
    int GetHeight() const { return GetHeight(_root); }
    int GetDegree() const { return GetDegree(_root); }
};

template <class T>
CSTreeNode<T> *ChildSiblingTree<T>::CreateTree(T nodes[], int parents[], int n, int rootIndex)
{ //nodes为节点数据数组，parents为对应的双亲索引，n为结点个数，r为根节点的索引位置
    if (rootIndex >= 0 && rootIndex < n)
    {
        CSTreeNode<T> *root = new CSTreeNode<T>(nodes[rootIndex]); //创建根节点
        CSTreeNode<T> *subRoot, *cur;
        for (int i = 0; i < n; i++)
        { //查找root的孩子
            if (parents[i] == rootIndex)
            {
                subRoot = CreateTree(nodes, parents, n, i); //递归构建子树
                if (root->_firstChild == NULL)
                { // subRoot(这颗字数的根)为root的第一个孩子
                    root->_firstChild = subRoot;
                }
                else
                { // subRoot(这颗字数的根)为cur的下一个兄弟
                    cur->_nextSibling = subRoot;
                }
                cur = subRoot; //cur记录当前遍历到的孩子
            }
        }
        return root;
    }
    else
        return NULL;
}

template <class T>
ChildSiblingTree<T>::ChildSiblingTree(T nodes[], int parents[], int n)
{
    _root = CreateTree(nodes, parents, n, 0);
}

template <class T>
void ChildSiblingTree<T>::Destroy(CSTreeNode<T> *&r)
{
}
template <class T>
CSTreeNode<T> *ChildSiblingTree<T>::GetRoot() const
{
    return _root;
}

template <class T>
CSTreeNode<T> *ChildSiblingTree<T>::GetFirstChild(CSTreeNode<T> *r) const
{ //封装这个函数，主要为了避免调用NULL的_firstChild时发生错误的情况
    if (r == NULL)
        return NULL;
    else
        return r->_firstChild;
}

template <class T>
CSTreeNode<T> *ChildSiblingTree<T>::GetNextSibling(CSTreeNode<T> *r) const
{ //封装这个函数，主要为了避免调用NULL的_nextSibling时发生错误的情况
    if (r == NULL)
        return NULL;
    else
        return r->_nextSibling;
}

template <class T>
int ChildSiblingTree<T>::GetHeight(CSTreeNode<T> *r) const
{
    if (r == NULL)
        return 0;
    else
    {
        CSTreeNode<T> *p;
        int subMaxHeight = 0;
        for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
        {
            int subHeight = GetHeight(p);
            subMaxHeight = (subMaxHeight > subHeight) ? subMaxHeight : subHeight;
        }
        return subMaxHeight + 1;
    }
}

template <class T>
int ChildSiblingTree<T>::GetNodeDegree(CSTreeNode<T> *r) const
{ //求单个结点r的度
    CSTreeNode<T> *p;
    int count = 0;
    for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
        count++;
    return count;
}
template <class T>
int ChildSiblingTree<T>::GetDegree(CSTreeNode<T> *r) const
{ //求以r为根节点的树的度
    CSTreeNode<T> *p;
    int maxDegree = GetNodeDegree(r);
    for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
    {
        int subMaxDegree = GetDegree(p);
        maxDegree = (maxDegree > subMaxDegree) ? maxDegree : subMaxDegree;
    }
    return maxDegree;
}

#endif