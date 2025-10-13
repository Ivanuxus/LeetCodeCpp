#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res = {};
        for (auto i = 1; i <= numRows; i++)
        {
            res.push_back(returnRow(i));
        }
        return res;
    }
    vector<int> returnRow(int n)
    {
        vector<int> res;
        res.push_back(1);
        if (n == 1)
        {
            return res;
        }
        res.push_back(1);
        if (n == 2)
        {
            return res;
        }
        res = {};
        vector<int> buffer;
        for (int i = 3; i <= n; i++)
        {
            vector<int>::iterator itFirst = buffer.begin();
            buffer.insert(itFirst, 1);
            vector<int>::iterator itLast = buffer.end();
            buffer.insert(itLast, 1);
            int sum = 0;
            for (int j = 0; j < buffer.size(); j++)
            {
                if (j + 1 < buffer.size())
                {
                    res.push_back(buffer[j] + buffer[j + 1]);
                }
            }
            buffer = res;
            if (n == i)
            {
                vector<int>::iterator itFirst = buffer.begin();
                buffer.insert(itFirst, 1);
                vector<int>::iterator itLast = buffer.end();
                buffer.insert(itLast, 1);
                return buffer;
            }
            res = {};
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> res = S.generate(6);
    for (auto i = 0; i < res.size(); i++)
    {
        for (auto j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}