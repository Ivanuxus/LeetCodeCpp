#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = 0;
        string s = to_string(n);
        bool Used = false;
        int counter = 0;
        while (true)
        {
            counter++;
            if (Used)
            {
                s = to_string(sum);
                sum = 0;
            }
            for (int i = 0; i < s.length(); i++)
            {
                sum += (s[i] - '0') * (s[i] - '0');
            }
            Used = true;
            if (sum == 1)
            {
                return true;
            }
            if (counter >= 100)
            {
                return false;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    int n = 0;
    cin >> n;
    cout << s.isHappy(n);
    return 0;
}