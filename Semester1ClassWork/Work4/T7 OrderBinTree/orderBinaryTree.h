//顺序二叉树
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    int Ref; //标记节点类型
    T data;
    Node() //默认构造
    {
    }
    Node(int r, const T &t) //非完全二叉树的结点
    {
        Ref = r;
        data = t;
    }
    Node(const T &t) //完全二叉树的结点
    {
        Ref = 0;
        data = t;
    }
    Node operator=(Node *a)
    {
        Ref = a->Ref;
        data = a->data;
    }
};

template <class T>
void CreateNodeArray(Node<T> *&a)
{
    Node<T> *List;
    List = new Node<T>[10];
    List[0] = new Node<T>(0, 0);
    List[1] = new Node<T>(1, 1);
    List[2] = new Node<T>(2, 2);
    List[3] = new Node<T>(1, 3);
    List[4] = new Node<T>(2, 4);
    List[5] = new Node<T>(1, 5);
    List[6] = new Node<T>(2, 6);
    List[7] = new Node<T>(1, 7);
    List[8] = new Node<T>(2, 8);
    List[9] = new Node<T>(1, 9);
    a = List;
}

template <class T>
class BinaryTree
{
protected:
    int _nodeNum;        //节点数
    int _rankNum;        //层数
    Node<T> *_dataArray; //里面全是指针
    int *_refArray;

public:
    BinaryTree(int nodeNum, Node<T> *data);              //完全二叉树
    BinaryTree(int nodeNum, Node<T> *data, int rankNum); //非完全二叉树
    void showper();
    void Find(int i, int j);
    void FindParent(int a, int b);
};

template <class T>
BinaryTree<T>::BinaryTree(int nodeNum, Node<T> *data) //创建完美二叉树
{
    _nodeNum = nodeNum;
    int rankNum = 0;
    for (int j = 1; (nodeNum = nodeNum - j) > 0; j = j * 2)
    // 计算层数
    {
        rankNum++;
    }
    rankNum++;
    _rankNum = rankNum;

    _dataArray = new Node<T>[_nodeNum];
    for (int i = 0; i < _nodeNum; i++)
    // 依次将元素放入数组
    {
        _dataArray[i] = data[i];
    }
}

template <class T>
void BinaryTree<T>::showper()
{
    int temp = 0;
    for (int i = 0; i < _rankNum; i++)
    {
        if (i == 0)
        {
            cout << _dataArray[i].data << endl;
            temp++;
        }
        else
        {
            if (temp > 0)
            {
                for (int j = 0; j < 2 * i; j++)
                { //决定每一层的输出个数
                    temp++;
                    cout << _dataArray[temp - 1].data << "  ";
                    if (temp == _nodeNum)
                    {
                        break;
                    }
                }
                cout << endl;
            }
        }
    }
}

template <class T>                     //寻找下标i j的共同祖先 输出下标位置
void BinaryTree<T>::Find(int a, int b) //使用完全二叉树
{
    int ta = a, tb = b;
    int ra, rb; //判断下标所在位置是左边还是右边
    for (int i = 0; i < _rankNum; i++)
    {
        int j = 1;
        for (int l = 0; l < i; l++)
        {
            j = j * 2;
        }
        ta = ta - j; //找下标在第几层
        if (ta < 0)
        {
            ta = ta + j; //找到后返回到这一层对应的位置
            if (ta < j / 2)
            { //若小于层数内所有点个数的一半，则在左边
                ra = 1;
            }
            else
            { //否则在右边
                ra = 2;
            }
            break;
        }
    }
    for (int i = 0; i < _rankNum; i++)
    { //找另一个下标的位置
        int j = 1;
        for (int l = 0; l < i; l++)
        {
            j = j * 2;
        }
        tb = tb - j;
        if (tb < 0)
        {
            tb = tb + j;
            if (tb < j / 2)
            {
                rb = 1;
            }
            else
            {
                rb = 2;
            }
            break;
        }
    }
    if (ra != rb)
    { //若左右不同，共同祖先一定是根
        cout << "共同祖先: 0" << endl;
        return;
    }
    if (a < b)
    { //若相同，一定是层数靠前的一个的父亲
        cout << "共同祖先: " << (a - 1) / 2 << endl;
    }
    else
    {
        cout << "共同祖先:" << (b - 1) / 2 << endl;
    }
}

template <class T>
void BinaryTree<T>::FindParent(int a, int b)
//寻找下标a,b的共同祖先 输出下标位置
{
    a = a + 1;
    b = b + 1;
    while ((a) / 2 != (b) / 2)
    {
        if (a < b)
            b /= 2;
        else
            a /= 2;
    }
    int result = a / 2 - 1;
    if (result < 0)
        cout << "共同祖先: " << 0 << endl;

    else
        cout << "共同祖先: " << result << endl;
}