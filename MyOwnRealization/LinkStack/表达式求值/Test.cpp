#include "SuffixExpreesion.h"
using namespace std;

int main()
{
    SeqList<string> SufxExpr = InputSufxExpr();
    cout << SufxExpr.GetLength() << endl;
    SufxExpr.DisplayList();
    double re = SufxExprCal(SufxExpr);
    cout << re;
    system("pause");
}