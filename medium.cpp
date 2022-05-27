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
