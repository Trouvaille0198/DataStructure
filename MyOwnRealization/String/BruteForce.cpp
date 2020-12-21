#include <bits/stdc++.h>
using namespace std;

int BF_find(const string &ob, const string &pat, const int p = 0)
//查找pat在ob中从位置p开始子串
{
    int i = p, j = 0;
    while (i < ob.length() && j < pat.length() && pat.length() - j <= ob.length() - i)
    {
        if (ob[i] == pat[j]) //匹配成功，继续匹配下个字符
        {
            i++;
            j++;
        }
        else //匹配失败
        {
            i = i - j + 1; //i退回到上趟匹配的下个字符位置
            j = 0;         //j从头开始
        }
    }
    if (j >= pat.length())
        return i - j;
    else
    {
        return -1;
    }
}

int main()
{
}