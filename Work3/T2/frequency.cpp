#include <bits/stdc++.h>
using namespace std;

void frequency(const string &str)
{
    string difChar;
    int freq[str.length()];
    for (int i = 0; i < str.length(); i++) //计数数组赋0值
    {
        freq[i] = 0;
    }

    for (int i = 0; i < str.length(); i++) //i constrols str[i]
    {
        int j = 0; //j controls difChar[j]
        while (difChar[j] != str[i] && j < difChar.length())
        //遍历difChar，寻找有无与str[i]相等的字符
        {
            j++;
        }
        if (j == difChar.length())
        //遍历到末尾，说明difChar中没有str[i]元素
        {
            freq[difChar.length()]++;
            difChar += str[i]; //add new char
        }
        else
        //此时difChar[j]遍历到对应str[i]的位置
        {
            freq[j]++;
        }
    }
    cout << "不同的字符有：";
    for (int i = 0; i < difChar.length(); i++)
    {
        cout << difChar[i] << " ";
    }
    cout << endl
         << "相应的频度为：";
    for (int i = 0; i < difChar.length(); i++)
    {
        cout << freq[i] << " ";
    }
}

int main()
{
    string str = "abcaabcb";
    frequency(str);
    /* string str1 = "123";
    char str2[] = {'1', '2', '3'};
    cout << (str1[0] == str2[0]) << endl; */
    system("pause");
}