#include "../../Tree/BinaryTree/BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinSortTree : public BinaryTree<T>
{
    // 继承二叉树的根节点数据成员
public:
    BinSortTree(T refvalue) : BinaryTree<T>(refvalue){};
    BinSortTree(T *a, int n); // 插入数组元素构建二叉排序树, 不用判断
    ~BinSortTree() {}
    void Insert(const T &x, BinTreeNode<T> *&p); // 以p为根节点, 按大小插入元素
    /*判定是否为二叉排序树*/
    bool IsBST_Recurve(BinTreeNode<T> *r, T *pre, bool *result); // 递归方式判断是否为二叉排序树
    bool IsBST_Recurve();
    void DisplayLarger(BinTreeNode<T> *p, const T &x); // 从大到小输出不小于x的元素
    void DisplayLarger(const T &x)
    {
        DisplayLarger(this->_root, x);
        cout << endl;
    }
};

template <class T>
BinSortTree<T>::BinSortTree(T *a, int n)
{
    for (int i = 0; i < n; i++)
        Insert(a[i], this->_root);
}

template <class T>
void BinSortTree<T>::Insert(const T &x, BinTreeNode<T> *&p)
{
    if (p == NULL)
        p = new BinTreeNode<T>(x);
    else
    {
        if (x < p->_data)
            Insert(x, p->_leftChild);
        else if (x > p->_data)
            Insert(x, p->_rightChild);
        else
            cout << "Error Inserting!" << endl;
    }
}

template <class T>
bool BinSortTree<T>::IsBST_Recurve(BinTreeNode<T> *r, T *pre, bool *result)
// 以r为根节点, 利用递归中序遍历, 判断是否为二叉排序树
{
    if (!r)
    {
        *result = true;
        //*pre = NULL;
        return *result;
    }
    if (r->_leftChild && *result)
        // 从树的最左开始判断, *result 默认为真
        IsBST_Recurve(r->_leftChild, pre, result); // 此时pre被赋值为当前节点的中序前驱
    if (r->_data < *pre)
        // 与其中序前驱相比较
        *result = false;
    *pre = r->_data; // 赋中序值
    if (r->_rightChild && *result)
        // 遍历右子树咯
        IsBST_Recurve(r->_rightChild, pre, result);
    return *result;
}

template <class T>
bool BinSortTree<T>::IsBST_Recurve()
{
    T pre;
    bool result = true;
    BinTreeNode<T> *p = this->_root;
    if (!p)
    {
        cout << "树为空!" << endl;
        return result;
    }
    IsBST_Recurve(p, &pre, &result);
    return result;
}

template <class T>
void BinSortTree<T>::DisplayLarger(BinTreeNode<T> *p, const T &x)
// 逆中序遍历
{
    if (p)
    {
        DisplayLarger(p->_rightChild, x);
        if (p->_data > x)
            cout << p->_data << " ";
        else
            return;
        DisplayLarger(p->_leftChild, x);
    }
}