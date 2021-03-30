#ifndef CHILD_SIBLING_TREE_NODE
#define CHILD_SIBLING_TREE_NODE

template <class T>
struct CSTreeNode
{
    T _data;
    CSTreeNode<T> *_firstChild;  //第一个孩子的指针域
    CSTreeNode<T> *_nextSibling; //下一个兄弟的指针域

    //构造函数
    CSTreeNode()
    {
        _firstChild = _nextSibling = NULL;
    }
    CSTreeNode(T data, CSTreeNode<T> *firstChild = NULL, CSTreeNode<T> *nextSibling = NULL)
        : _data(data), _firstChild(firstChild), _nextSibling(nextSibling) {}
};

#endif