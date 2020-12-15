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

    cout << "输入后缀表达式：" << endl;
    while (cin.peek() != '\n')
    {
        cin >> str[count++];
    }

    SeqList<string> SufxExpr(str, count);
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
    //根据操作符计算结果
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
    result = Operand.TopElem();
    return result;
}

SeqList<string> InputInfxExpr()
//接收一个中缀表达式，返回顺序表
{
    int count = 0;
    string str[100];

    cout << "输入中缀表达式" << endl;
    while (cin.peek() != '\n')
    {
        cin >> str[count++];
    }

    SeqList<string> InfxExpr(str, count);
    return InfxExpr;
}

int OperatorPrior(string opr1, string opr2)
{
    int prior;
    char op1 = opr1[0], op2 = opr2[0];
    switch (op1)
    {
    case '+':
    case '-':
        if (op2 == '(')
            prior = 1;
        else
            prior = 0;
        break;
    case '*':
    case '/':
        if (op2 == '^' || op2 == '*' || op2 == '/')
            prior = 0;
        else
            prior = 1;
        break;
    case '^':
        prior = 1;
        break;
    case '(':
        prior = 1;
        break;
    case ')':
        if (op2 == '(') //右括号遇到左括号时，消除该对括号，优先级取-1
            prior = -1;
        else
            prior = -2;
        break;
    }
    return prior;
}

SeqList<string> InfxExprToSufxExpr(SeqList<string> InfxExpr)
//将中缀表达式转换成后缀表达式
{
    SeqList<string> SufxExpr;
    LinkStack<string> Oprt; //操作符栈
    string str;
    for (int i = 1; i <= InfxExpr.GetLength(); i++)
    {
        str = InfxExpr.GetElem(i);
        if (IsNum(str)) //如果是数字，直接写入结果
        {
            SufxExpr.InsertElem(str);
        }
        else
        {
            if (Oprt.IsEmpty())
                Oprt.PushElem(str);
            else if (OperatorPrior(str, Oprt.TopElem()) == 1) //高优先级操作符或者左括号，直接入栈
                Oprt.PushElem(str);
            else if (OperatorPrior(str, Oprt.TopElem()) == 0)
            {
                while (!(Oprt.IsEmpty()) && OperatorPrior(str, Oprt.TopElem()) == 0)
                {
                    SufxExpr.InsertElem(Oprt.TopElem());
                    Oprt.PopElem();
                }
                Oprt.PushElem(str);
            }
            else if (OperatorPrior(str, Oprt.TopElem()) == -2) //右括号
            {
                while (OperatorPrior(str, Oprt.TopElem()) != -1)
                {
                    SufxExpr.InsertElem(Oprt.TopElem());
                    Oprt.PopElem();
                }
                Oprt.PopElem();
            }
        }
    }
    while (!(Oprt.IsEmpty()))
    {
        SufxExpr.InsertElem(Oprt.TopElem());
        Oprt.PopElem();
    }
    return SufxExpr;
}

#endif