#include <iostream>
#include <vector>
class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int countOfZeroes = 0;
        std::vector<int> result = {};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                countOfZeroes++;
            }
            else
            {
                result.push_back(nums[i]);
            }
        }
        while (countOfZeroes != 0)
        {
            result.push_back(0);
            countOfZeroes--;
        }
        nums = result;
    }
};
int main()
{
    std::vector<int> nums = {0, 1, 0, 3, 12};
    Solution S;
    S.moveZeroes(nums);
    return 0;
}