#include <string>
#include <stdio.h>
#include <vector>
class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        std::vector<std::string> resulted = {};
        long long i = 0;
        while (i < (nums.size()))
        {
            long long currentNumb = nums[i];
            long long endNumb = nums[i];
            bool fetching = false;
            for (long long j = i + 1; j < nums.size(); j++)
            {
                if (((long long)nums[j] - (long long)nums[j - 1]) == 1)
                {
                    endNumb = nums[j];
                    fetching = true;
                }
                else
                {
                    if (fetching)
                    {
                        i = j;
                    }
                    break;
                }
            }
            if (currentNumb != endNumb)
            {
                resulted.push_back(std::string(std::string(std::to_string(currentNumb)) + "->" + std::string(std::to_string(endNumb))));
                if (endNumb == nums[nums.size() - 1])
                {
                    i = 99;
                }
            }
            else if (currentNumb == endNumb)
            {
                resulted.push_back(std::string(std::to_string(currentNumb)));
                if (currentNumb == nums[nums.size() - 1])
                {
                    i = 99;
                }
            }
            if (!fetching)
            {
                i++;
                fetching = false;
            }
        }
        return resulted;
    }
};
int main()
{
    Solution s;
    std::vector<int> nums = {-2147483648,0,2,3,4,6,8,9};
    s.summaryRanges(nums);
    return 0;
}