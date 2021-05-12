#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinAVLTreeNode
{
public:
    T _data;
    int _bf; // 平衡因子
    int _lsize;
    BinAVLTreeNode<T> *_leftChild;
    BinAVLTreeNode<T> *_rightChild;

    BinAVLTreeNode() {}
    BinAVLTreeNode(const T &data, int bf = 0,
                   BinAVLTreeNode<T> *leftChild = NULL,
                   BinAVLTreeNode<T> *rightChild = NULL)
        : _data(data), _bf(bf), _leftChild(leftChild), _rightChild(rightChild) {}
};