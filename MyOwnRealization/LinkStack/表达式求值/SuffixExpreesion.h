#ifndef RPN
#define RPN
#include "D:\repo\DataStructure\MyOwnRealization\SeqList\SeqList.h"
#include "D:\repo\DataStructure\MyOwnRealization\SeqStack\SeqStack.h"
#include <bits/stdc++.h>
using namespace std;

SeqList<string> InputSufxExpr()
//接收一个后缀表达式，返回顺序表
{
    int count = 0;
    string str[100];

    cout << "输入后缀表达式，以“#”号结束：" << endl;
    while (cin.peek() != '\n')
    {
        //getline(cin, str[count++]);
        cin >> str[count++];
    }

    /*
    另一种输入实现
    char c;
    while ((c = getchar()) != '#')
    {
        ch[count++] = c;
    }
    */

    SeqList<string> SufxExpr(str, count - 1);
    return SufxExpr;
}

double SufxExprCal(SeqList<string> &SufxExpr)
//后缀表达式计算结果
{
    double result, first, second;
    SeqList<double> operand; //操作数栈
    for (int i = 1; i <= SufxExpr.GetLength(); i++)
    {
        while (isdigit(SufxExpr.GetElem(i)) || SufxExpr.GetElem(i) == ".")
        {

            i++;
        }
    }
}

#endif