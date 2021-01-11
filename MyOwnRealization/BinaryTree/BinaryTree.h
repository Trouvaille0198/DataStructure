//二叉树的二叉链表类模板
#include "../LinkQueue/LinkQueue.h"
#include "../LinkStack/LinkStack.h"
#include "BinTreeNode.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinaryTree
{
protected:
    BinTreeNode<T> *_root; //二叉树根节点的指针
    //辅助函数
    /* 创建二叉树 */
    /* 遍历二叉树 */
    void PreOrder(const BinTreeNode<T> *root) const;            //前序遍历
    void InOrder(const BinTreeNode<T> *root) const;             //中序遍历
    void PostOrder(const BinTreeNode<T> *root) const;           //后序遍历
    void PreOrder_NoRecurve(const BinTreeNode<T> *root) const;  //前序遍历非递归
    void InOrder_NoRecurve(const BinTreeNode<T> *root) const;   //中序遍历非递归
    void PostOrder_NoRecurve(const BinTreeNode<T> *root) const; //后序遍历非递归
    void LevelOrder(const BinTreeNode<T> *root) const;          //层次遍历
    /* 获取信息 */
    int GetHeight(const BinTreeNode<T> *root) const;  //求高度
    int GetNodeNum(const BinTreeNode<T> *root) const; //求节点个数
    /* 其他 */
    BinTreeNode<T> *CopyTree(BinTreeNode<T> *t); //复制二叉树
    void DestroyTree(BinTreeNode<T> *&root);     //删除二叉树
public:
    /* 构造与析构 */
    BinaryTree() : _root(NULL);
    BinaryTree(const T &e) : _root(e);
    virtual ~BinaryTree() { DestroyTree(_root); };
    /* 创建二叉树 */

    /* 遍历二叉树 */
    void PreOrder() const { PreOrder(_root); }
    void InOrder() const { InOrder(_root); }
    void PostOrder() const { PostOrder(_root); }
    void PreOrder_NoRecurve() const { PreOrder(_root); }
    void InOrder_NoRecurve() const { InOrder(_root); }
    void PostOrder_NoRecurve() const { PostOrder(_root); }
    /* 获取信息 */
    BinTreeNode<T> *GetRoot() { return _root; }
    int GetHeight() const { GetHeight(_root); }
    int GetNodeNum() const { GetNodeNum(_root); }
    BinTreeNode<T> *GetParent(const BinTreeNode<T> *p) const { return (_root == NULL || _root == p) ? NULL : Parent(_root, p); }
    BinTreeNode<T> *GetLeftChild(const BinTreeNode<T> *p) const { return (p == NULL) ? NULL : p->_leftChild; }
    BinTreeNode<T> *GetRightChild(const BinTreeNode<T> *p) const { return (p == NULL) ? NULL : p->_rightChild; }
    /* 其他 */
    BinTreeNode<T> *CopyTree() { CopyTree(_root); }
    void DestroyTree() { DestroyTree(_root); }
    bool IsEmpty() const { return (root == NULL) ? true : false; }
    T GetElem(BinTreeNode<T> *p);
    void SetElem(BinTreeNode<T> *p, T data)
};

template <class T>
void BinaryTree<T>::PreOrder(const BinTreeNode<T> *root) const
{
    if (root != NULL)
    {
        PreOrder(root->_leftChild);
        cout << root->_data << " ";
        PreOrder(root->_rightChild);
    }
}

template <class T>
void BinaryTree<T>::InOrder(const BinTreeNode<T> *root) const
{
    if (root != NULL)
    {
        PreOrder(root->_leftChild);
        PreOrder(root->_rightChild);
        cout << root->_data << " ";
    }
}

template <class T>
void BinaryTree<T>::PostOrder(const BinTreeNode<T> *root) const
{
    if (root != NULL)
    {
        cout << root->_data << " ";
        PreOrder(root->_leftChild);
        PreOrder(root->_rightChild);
    }
}

template <class T>
void BinaryTree<T>::PreOrder_NoRecurve(const BinTreeNode<T> *root) const
//DLR 节点不为空时即打印
{
    if (root == NULL)
        return;
    LinkStack<BinTreeNode<T> *> Stack;
    BinTreeNode<T> *p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            cout << p->_data << " "; //先打印父节点
            Stack.PushElem(p);       //父节点入栈
            p = p->_leftChild;       //转到左节点
        }
        else
        {
            p = Stack.TopElem(); //回溯到父节点
            Stack.PopElem();     //父节点出栈
            p = p->_rightChild;  //转到右节点
        }
    }
}

template <class T>
void BinaryTree<T>::InOrder_NoRecurve(const BinTreeNode<T> *root) const
//LDR 左节点为空时访问（或 即将转到右节点时访问）
{
    if (root == NULL)
        return;
    LinkStack<BinTreeNode<T> *> Stack;
    BinTreeNode<T> *p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            Stack.PushElem(p); //入栈
            p = p->_leftChild; //转到左节点
        }
        else
        {
            p = Stack.TopElem();
            Stack.PopElem();         //栈顶出栈
            cout << p->_data << " "; //即将转到右节点时，打印栈顶
            p = p->_rightChild;      //转到右节点
        }
    }
}

template <class T>
void BinaryTree<T>::PostOrder_NoRecurve(const BinTreeNode<T> *root) const
//LRD 出栈时，需要判定左右节点遍历的完成情况
{
    if (_root == NULL)
        return;
    LinkStack<BinTreeNode<T> *> Stack;
    LinkStack<BinTreeNode<T> *> Tag;
    BinTreeNode<T> *p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            Stack.PushElem(p);
            Tag.PushElem(0);
            p = p->_leftChild;
        }
        else
        {
            if (Tag.TopElem() == 0) //此时左节点已经遍历完
            {
                p = Stack.TopElem(); //预出栈
                Tag.PopElem();
                Tag.PushElem(0); //将Tag栈顶改为1，表示已经遍历完左节点
            }
            else //此时右节点已经遍历完
            {
                p = Stack.TopElem();
                Stack.PopElem(); //真正出栈
                Tag.PopElem();
                cout << p->_data << " ";
            }
        }
    }
}

template <class T>
void BinaryTree<T>::LevelOrder(const BinTreeNode<T> *root) const
//层序遍历
{
    LinkQueue<BinTreeNode<T> *> Queue;
    BinTreeNode<T> *p;
    if (root != NULL)
        Queue.EnterQueue(root); //若根非空，则入队
    while (!Queue.IsEmpty())
    {
        p = Queue.GetFront();    //取队头
        Queue.DeleteQueue();     //出队
        cout << p->_data << " "; //打印打印！

        if (p->_leftChild != NULL) //若左节点非空，入队
        {
            Queue.EnterQueue(p->_leftChild);
        }
        if (p->_rightChild != NULL) //若右节点非空，入队
        {
            Queue.EnterQueue(p->_rightChild);
        }
    }
}