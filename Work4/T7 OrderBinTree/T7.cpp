//找出A[i],A[j]最近的共同祖先

#include "orderBinaryTree.h"
using namespace std;

//             0
//          1      2
//        3   4   5 6
//      7  8 9

int main()
{
  Node<int> *TreeNode1;
  CreateNodeArray(TreeNode1);
  BinaryTree<int> Tree(10, TreeNode1);
  //Tree.showper();
  int a, b;
  while (cin >> a >> b)
  {
    Tree.FindParent(a, b);
  }
  system("pause");
}
