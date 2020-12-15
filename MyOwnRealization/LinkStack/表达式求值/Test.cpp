#include "SuffixExpreesion.h"
using namespace std;

int main()
{
    SeqList<string> SufxExpr = InputSufxExpr();
    cout << SufxExpr.GetLength() << endl;
    SufxExpr.DisplayList();
    system("pause");
}