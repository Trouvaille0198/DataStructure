#ifndef RPN
#define RPN
#include "../../SeqList/SeqList.h"
#include "../LinkStack.h"
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

    SeqList<string> SufxExpr(str, count - 1);
    return SufxExpr;
}

bool IsNum(string str)
{
    stringstream sin(str);
    double d;
    char c;
    if (!(sin >> d)) //表示把sin转换成double的变量（其实对于int和float型的都会接收）
        return false;
    if (sin >> c) //此部分用于检测错误输入中，数字加字符串的输入形式
        return false;
    return true;
}

bool IsOperator(string str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/" || str == "^")
        return true;
    else
    {
        return false;
    }
}

double Calculate(double first, double second, string opr)
{
    double result;
    switch (opr[0])
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        result = first / second;
        break;
    case '^':
        result = pow(first, second);
        break;
    }
    return result;
}

double SufxExprCal(SeqList<string> &SufxExpr)
//后缀表达式计算结果
{
    double result = 0, first, second;
    LinkStack<double> Operand; //操作数栈
    for (int i = 1; i <= SufxExpr.GetLength(); i++)
    {
        if (IsNum(SufxExpr.GetElem(i))) //如果是操作数
        {
            Operand.PushElem(stod(SufxExpr.GetElem(i)));
        }
        else
        {
            second = Operand.TopElem(); //取第二操作数
            Operand.PopElem();
            first = Operand.TopElem(); //取第一操作数
            Operand.PopElem();
            Operand.PushElem(Calculate(first, second, SufxExpr.GetElem(i)));
            //两操作数出栈计算，将结果重新入栈
        }
    }
    return result;
}

#endif