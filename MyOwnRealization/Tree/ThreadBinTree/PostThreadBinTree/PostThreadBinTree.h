#include "../../../LinkQueue/LinkQueue.h"
#include "../../../LinkStack/LinkStack.h"
#include <bits/stdc++.h>
using namespace std;

//线索二叉树结点类
template <typename T>
struct ThreadNode //结点类
{
    int _leftTag, rightTag;                  //为0时记录子节点，为1时记录前驱或后继                                                                             //左右子树标志位
    ThreadNode<T> *_leftChild, *_rightChild; //左孩子和右孩子
    T _data;                                 //结点存储的值
    ThreadNode(const T data) : _data(data),
                               leftChild(NULL), rightChild(NULL), leftTag(0), rightTag(0) {}
};

template <typename T>
class ThreadTree
{
private:
    ThreadNode<T> *_root;

public:
    ThreadTree() : _root(NULL) {}
};

template <typename T>
class PostThreadBinTree
{
};