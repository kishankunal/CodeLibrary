//https://www.codingninjas.com/codestudio/problems/product-array-puzzle_983600?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

vector<int> productPuzzle(vector<int> &arr, int n)
{

    vector<int> product(n, 0);

    vector<int> prefix(n, 0);
 
    vector<int> suffix(n, 0);


    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            prefix[i] = arr[i];
        }
        else
        {
            prefix[i] = (int)(((long)prefix[i - 1] * arr[i]) % mod);
        }
    }

    // Calculating the suffix product.
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            suffix[i] = arr[i];
        }
        else
        {
            suffix[i] = (int)(((long)suffix[i + 1] * arr[i]) % mod);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        // Handling the corners cases.
        if (i == 0)
        {
            product[i] = suffix[i + 1];
        }
        else if (i == n - 1)
        {
            product[i] = prefix[i - 1];
        }
        else
        {
            product[i] = (int)(((long)prefix[i - 1] * suffix[i + 1]) % mod);
        }
    }

    return product;
}