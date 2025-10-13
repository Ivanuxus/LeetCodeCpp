#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        res.push_back(1);
        if (rowIndex == 0)
        {
            return res;
        }
        res.push_back(1);
        if (rowIndex == 1)
        {
            return res;
        }
        res = {};
        vector<int> buffer;
        for (int i = 2; i <= rowIndex; i++)
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
            if (rowIndex == i)
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
    vector<int> res = S.getRow(6);
    for (auto i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}