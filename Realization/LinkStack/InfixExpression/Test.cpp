#include "Expreesion.h"
using namespace std;

int main()
{
    SeqList<string> InfxExpr = InputInfxExpr();
    cout << InfxExpr.GetLength() << endl;
    //cout<<InfxExpr.Display();
    SeqList<string> SufxExpr = InfxExprToSufxExpr(InfxExpr);
    cout << "转换成后缀表达式为：";
    SufxExpr.Display();
    cout << "Result:" << SufxExprCal(SufxExpr) << endl;

    system("pause");
}