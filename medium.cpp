#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void helper(int open, int close, vector<string> &v, string str)
{
    if (open == 0 && close == 0)
    {
        v.push_back(str);
        return;
    }
    if (open == close)
    {
        helper(open - 1, close, v, str + "(");
    }
    if (open < close)
    {
        if (open == 0)
        {
            helper(open, close - 1, v, str + ")");
        }
        else
        {
            helper(open - 1, close, v, str + "(");
            helper(open, close - 1, v, str + ")");
        }
    }
}

vector<string> generateParenthesis(int n)
{
    int open = n, close = n;
    vector<string> v;
    helper(open, close, v, "");
    return v;
}

int totalFruit(vector<int> &fruits)
{
    int s = 0, e = 0, maxLength = 0;
    unordered_map<int, int> map;
    while (e < fruits.size())
    {
        if (!map.count(fruits[e]))
        {
            map[fruits[e]] = 1;
        }
        else
        {
            map[fruits[e]]++;
        }
        while (map.size() > 2)
        {
            map[fruits[s]]--;
            if (map[fruits[s]] == 0)
            {
                map.erase(fruits[s]);
            }
            s++;
        }
        maxLength = max(maxLength, e - s + 1);
        e++;
    }
    return maxLength;
}

void printAllPathInMaze(vector<vector<int> > &maze, int r, int c, int i)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        maze[r][c] = i;
        for (int i = 0; i < maze.size(); i++)
        {
            for (int j = 0; j < maze[i].size(); j++)
            {
                    cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (maze[r][c])
        return;
    maze[r][c] = i;
    // UP
    if (r > 0)
    {
        printAllPathInMaze(maze, r - 1, c, i + 1);
    }
    // DOWN
    if (r < maze.size() - 1)
    {
        printAllPathInMaze(maze, r + 1, c, i + 1);
    }
    // Left
    if (c > 0)
    {
        printAllPathInMaze(maze, r, c - 1, i + 1);
    }
    // Right
    if (c < maze[0].size() - 1)
    {
        printAllPathInMaze(maze, r, c + 1, i + 1);
    }
    maze[r][c] = 0;
    return;
}

