#include <vector>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int current = nums[i];
            bool once = true;
            for (int j = i + 1; j < n; j++)
            {
                if (current == nums[j])
                {
                    once = false;
                    nums.erase(nums.begin() + j);
                    n--;
                    break;
                }
            }
            if (once)
            {
                return nums[i];
            }
        }
        return 0;
    }
};

int main()
{
    Solution S;
    vector<int> prices = {2, 2, 1};
    auto result = S.singleNumber(prices);
    printf("%d", result);
}