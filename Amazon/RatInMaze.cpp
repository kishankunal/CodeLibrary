//https://classroom.codingninjas.com/app/classroom/me/930/content/13794/offering/119290/problem/905

#include <bits/stdc++.h>
using namespace std;

void rat(int maze[][20], int row, int col, int n, int **solution)
{
    if (row == n - 1 && col == n - 1)
    {
        solution[row][col] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    if (row >= n || row < 0 || col >= n || col < 0 || maze[row][col] == 0 || solution[row][col] == 1)
    {
        return;
    }
    solution[row][col] = 1;
    rat(maze, row - 1, col, n, solution);
    rat(maze, row + 1, col, n, solution);
    rat(maze, row, col - 1, n, solution);
    rat(maze, row, col + 1, n, solution);
    solution[row][col] = 0;
}

void ratInAMaze(int maze[][20], int n)
{
    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }
    rat(maze, 0, 0, n, solution);
    return;
}
