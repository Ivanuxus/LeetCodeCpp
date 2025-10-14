#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < i + k + 1; ++j)
            {
                if (j >= nums.size())
                {
                    continue;
                }
                if (nums[i] == nums[j])
                {
                    if (i > j)
                    {
                        if ((i - j) <= k)
                        {
                            return true;
                        }
                    }
                    else if (i < j)
                    {
                        if ((j - i) <= k)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {
        1};
    int k = 1;
    Solution S;
    printf("%d", S.containsNearbyDuplicate(nums, k));
}