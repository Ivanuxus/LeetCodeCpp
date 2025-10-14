#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int counter = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                {
                    counter++;
                }
            }
            if ((counter > (nums.size() / 2)))
            {
                return nums[i];
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {6, 5, 5};
    Solution S;
    printf("%d", S.majorityElement(nums));
}