//顺序二叉树
#include <iostream>
#include <iomanip>
using namespace std;

template <class ElemType>
class Node
{
public:
    int _RefValue; //标记节点类型
    ElemType data;
    Node() //默认构造函数
    {
    }
    Node(int r, const ElemType &t) //非完美二叉树的结点
    {
        _RefValue = r;
        data = t;
    }
    Node(const ElemType &t) //完美二叉树的结点
    {
        _RefValue = 0;
        data = t;
    }
    Node operator=(Node *a)
    {
        _RefValue = a->_RefValue;
        data = a->data;
    }
};

template <class ElemType>
void CreateNodeArray(Node<ElemType> *&a)
{
    Node<ElemType> *List;
    List = new Node<ElemType>[10];
    List[0] = new Node<ElemType>(0, 10);
    List[1] = new Node<ElemType>(1, 9);
    List[2] = new Node<ElemType>(2, 8);
    List[3] = new Node<ElemType>(1, 7);
    List[4] = new Node<ElemType>(2, 6);
    List[5] = new Node<ElemType>(1, 5);
    List[6] = new Node<ElemType>(2, 4);
    List[7] = new Node<ElemType>(1, 3);
    List[8] = new Node<ElemType>(2, 2);
    List[9] = new Node<ElemType>(1, 1);
    a = List;
}

template <class ElemType>
class BinaryTree
{
protected:
    int NodeNum;
    int RankNum;
    Node<ElemType> *DataArray; //里面全是指针
    int *_RefValueArray;

public:
    BinaryTree(int nodenum, Node<ElemType> *data);              //完美二叉树
    BinaryTree(int nodenum, Node<ElemType> *data, int ranknum); //非完美二叉树
    void showper();
    void Find(int i, int j);
};

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(int nodenum, Node<ElemType> *data) //创建完美二叉树
{
    NodeNum = nodenum;
    int ranknum = 0;
    for (int j = 1; (nodenum = nodenum - j) > 0; j = j * 2)
    {
        ranknum++;
    }
    ranknum++;
    RankNum = ranknum;
    /*
    int n;
    int s=0;
    for(int i=1,n=1; i<=ranknum; i++){
        s = s+n;
        n = n*2;
    }
    */
    DataArray = new Node<ElemType>[NodeNum];
    for (int i = 0; i < NodeNum; i++)
    {
        DataArray[i] = data[i];
    }
}

template <class ElemType>
void BinaryTree<ElemType>::showper()
{
    int temp = 0;
    for (int i = 0; i < RankNum; i++)
    {
        cout << setw(25) << ""
             << "The " << i << " floor:" << setw(5) << "";
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

template <class ElemType>                     //寻找下标i j的共同祖先 输出下标位置
void BinaryTree<ElemType>::Find(int a, int b) //建立在完美二叉树
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
        cout << setw(25) << ""
             << "共同祖先:根 0" << endl;
        return;
    }
    if (a < b)
    { //若相同，一定是层数靠前的一个的父亲
        cout << setw(25) << ""
             << "共同祖先:" << (a - 1) / 2 << endl;
    }
    else
    {
        cout << setw(25) << ""
             << "共同祖先:" << (b - 1) / 2 << endl;
    }
}
