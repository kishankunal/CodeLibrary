//https://practice.geeksforgeeks.org/problems/word-search/0/?track=amazon-graphs&batchId=192
#include <bits/stdc++.h>
using namespace std;

int r[4] = {1, 0, -1, 0};
int c[4] = {0, -1, 0, 1};
bool dfs(vector<vector<char>> board, int x, int y, int n, int m, string word, int index)
{
    if (index >= word.size())
    {
        return true;
    }
    if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] != word[index])
    {
        return false;
    }
    board[x][y] = '#';
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        flag = flag | dfs(board, x + r[i], y + c[i], n, m, word, index + 1);
    }
    board[x][y] = word[index];
    return flag;
}
bool isWordExist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                if (dfs(board, i, j, n, m, word, 0))
                {
                    return true;
                }
            }
        }
    }
    return false;
}