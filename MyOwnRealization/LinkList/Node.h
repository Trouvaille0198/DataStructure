#ifndef NODE
#define NODE

template <class DataType>
struct Node
{

    DataType _data;        // 数据域
    Node<DataType> *_next; // 指针域

    Node(Node<DataType> *next = NULL); // 无参构造函数
    Node(DataType e, Node<DataType> *next = NULL);
};

template <class DataType>
Node<DataType>::Node(Node<DataType> *next)
//构造指针域为空的结点
{
    _next = next;
}

template <class DataType>
Node<DataType>::Node(DataType e, Node<DataType> *link)
//构造一个数据域为e和指针域为next的结点
{
    _data = e;
    _next = link;
}

#endif
