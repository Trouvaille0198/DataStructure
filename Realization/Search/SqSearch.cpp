#include <bits/stdc++.h>
using namespace std;

template <class T>
int SqSearch1(T elem[], int n, T key)
{
    for (int i = 0; i < n && elem[i] != key; i++)
        ;
    if (i < n)
        return i;
    else
        return -1;
}

template <class T>
int SqSearch2(T elem[], int n, T key)
{
    elem[0] = key;
    int i = n;
    while (elem[i] != key)
        i--;
    return i;
}
int main()
{
    system("pause");
}