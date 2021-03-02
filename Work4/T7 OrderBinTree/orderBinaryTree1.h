//顺序二叉树
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    int Ref; //标记是什么，根， 左， 右
    T data;
    Node() //默认构造
    {
    }
    Node(int r, const T &t) //非完美二叉树的结点
    {
        Ref = r;
        data = t;
    }
    Node(const T &t) //完美二叉树的结点
    {
        Ref = 0;
        data = t;
    }
    Node &operator=(Node *a)
    {
        Ref = a->Ref;
        data = a->data;
        return *this;
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
    int NodeNum;        //节点数
    int RankNum;        //层数
    Node<T> *DataArray; //里面全是指针
    int *refArray;

public:
    BinaryTree(int nodenum, Node<T> *data);              //完美二叉树
    BinaryTree(int nodenum, Node<T> *data, int ranknum); //非完美二叉树
    void showper();
    void Find(int i, int j);
};

template <class T>
BinaryTree<T>::BinaryTree(int nodenum, Node<T> *data) //创建完美二叉树
{
    NodeNum = nodenum;
    int ranknum = 0;
    for (int j = 1; (nodenum = nodenum - j) > 0; j = j * 2)
    {
        ranknum++;
    }
    ranknum++;
    RankNum = ranknum;

    DataArray = new Node<T>[NodeNum];
    for (int i = 0; i < NodeNum; i++)
    {
        DataArray[i] = data[i];
    }
}

template <class T>
void BinaryTree<T>::showper()
{
    int temp = 0;
    for (int i = 0; i < RankNum; i++)
    {
        cout << ""
             << "第" << i << "层:"
             << " ";
        if (i == 0)
        {
            cout << DataArray[i].data << endl;
            temp++;
        }
        else
        {
            if (temp > 0)
            {
                for (int j = 0; j < 2 * i; j++)
                { //决定每一层的输出个数
                    temp++;
                    cout << DataArray[temp - 1].data << "  ";
                    if (temp == NodeNum)
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
void BinaryTree<T>::Find(int a, int b) //建立在完美二叉树
{
    int ta = a, tb = b;
    int ra, rb; //判断下标所在位置是左边还是右边
    for (int i = 0; i < RankNum; i++)
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
    for (int i = 0; i < RankNum; i++)
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
