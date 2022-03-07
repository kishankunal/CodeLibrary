#include <bits/stdc++.h>
using namespace std;

int snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<bool> vis(101, false);
    unordered_map<int, int> ladder, snack;
    for (int i = 0; i < A.size(); i++)
    {
        ladder[A[i][0]] = A[i][1];
    }

    for (int i = 0; i < B.size(); i++)
    {
        snack[B[i][0]] = B[i][1];
    }
    queue<int> q;
    q.push(1);
    bool found = false;
    int move = 0;
    while (!found and !q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int d = 1; d <= 6; d++)
            {
                
                if (t + d <= 100 and ladder[t + d] and !vis[t + d])
                {
                    vis[t + d] = true;
                    if (ladder[t + d] == 100)
                    {
                        found = true;
                    }
                    q.push(ladder[t + d]);
                }
                else if (t + d <= 100 and snack[t + d] and !vis[t + d])
                {
                    vis[t + d] = true;
                    q.push(snack[t + d]);
                }
                else if (t + d <= 100 and !snack[t + d] and !ladder[t + d] and !vis[t + d])
                {
                    vis[t + d] = true;
                    if (t + d == 100)
                    {
                        found = true;
                    }
                    q.push(t + d);
                }
            }
        }
        move++;
    }
    if (found)
        return move;
    return -1;
}
