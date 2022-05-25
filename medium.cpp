#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

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