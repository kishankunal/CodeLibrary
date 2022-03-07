#include <bits/stdc++.h>
using namespace std;

string intToRoman(int A)
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    string str = "";
    while (A > 0)
    {
        int quo = A / num[i];
        A = A % num[i];
        while (quo)
        {
            str += sym[i];
            quo--;
        }
        i--;
    }
    return str;
}