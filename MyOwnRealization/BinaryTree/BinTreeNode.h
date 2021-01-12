#ifndef BINTREENODE_H
#define BINTREENODE_H
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class BinTreeNode
{
public:
    DataType _data;
    BinTreeNode<DataType> *_leftChild;
    BinTreeNode<DataType> *_rightChild;

    BinTreeNode() : _leftChild(NULL), _rightChild(NULL) {}
    BinTreeNode(const DataType data,
                BinTreeNode<DataType> *leftChild = NULL,
                BinTreeNode<DataType> *rightChild = NULL)
        : _data(data), _leftChild(leftChild), _rightChild(rightChild) {}
};

#endif