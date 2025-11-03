#include <iostream>
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long num = 1;
        while (n >= num)
        {
            if (n == num)
            {
                return true;
            }
            num *= 2;
        }
        return false;
    }
};
int main()
{
    Solution s;
    std::cout << "\n"
              << s.isPowerOfTwo(16);
    return 0;
}