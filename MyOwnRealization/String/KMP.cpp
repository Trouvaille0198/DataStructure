#include <bits/stdc++.h>
using namespace std;

void GetNext(const string &pat, int *next)
//p[k]表示前缀，p[j]表示后缀
{
    int j = 0, k = -1;
    next[0] = -1; //设next[0]的初始值为-1
    while (pat[j] != '\0')
    {
        if (k == -1 || pat[j] == pat[k])
        {
            j++;
            k++;         //j,k向后走
            next[j] = k; //记录到此索引前字符串真子串的长度
        }
        else
            k = next[k]; //寻求新的匹配字符
    }
}

int KMP(const string &ob, const string &pat, const int start = 0)
{
    int *next = new int[pat.length()];
    GetNext(pat, next);
    int i = start, j = 0;
    while ((j == -1) || (ob[i] != '\0' && pat[j] != '\0'))
    {
        if (j == -1 || ob[i] == pat[j])
        {
            i++; //继续对下一个字符比较
            j++; //模式串向右滑动
        }
        else
            j = next[j]; //寻找新的匹配字符位置，模式串尽可能向右滑动
    }
    //delete[] next;
    if (pat[j] == '\0')
        return (i - j); //匹配成功返回下标
    else
        return -1; //匹配失败返回-1
}

int main()
{
    string a = "aabbc";
    string b = "bc";
    cout << KMP(a, b) << endl;
    system("pause");
}