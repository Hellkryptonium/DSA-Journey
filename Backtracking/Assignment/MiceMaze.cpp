#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int maze[4][4], int n, int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] != 0)
    {
        return true;
    }
    return false;
}

void solveMaze(int maze[4][4], int n, vector<vector<int>> &path, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        cout << "Path found: " << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i][0] << " " << path[i][1] << " -> ";
        }
        cout << x << " " << y;
        cout << endl;
        return;
    }

    if (isSafe(maze, n, x, y))
    {
        maze[x][y] = 0;
        path.push_back({x, y});
        // Right Move
        solveMaze(maze, n, path, x, y + 1);
        // Down Move
        solveMaze(maze, n, path, x + 1, y);
        // Left Move
        solveMaze(maze, n, path, x, y - 1);
        // Up Move
        solveMaze(maze, n, path, x - 1, y);
        maze[x][y] = 1;
        path.pop_back();
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> path;
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1}};
    solveMaze(maze, n, path, 0, 0);
}