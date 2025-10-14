#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int>::iterator it = prices.end() - 1;
        while (*it == 0 && prices.size() > 0)
        {
            prices.pop_back();
            it = prices.end();
        }
        long minDelta = 0;
        bool sorted = true;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if ((prices[i] < prices[i + 1]))
            {
                // printf("%d,%d\n", prices[i], prices[i + 1]);
                sorted = false;
                break;
            };
        }
        if (!sorted)
        {
            auto minValue = std::min_element(prices.begin(), prices.end());
            auto maxValue = std::max_element(prices.begin(), prices.end());
            // printf("MinMAxValue:%d, %d\n", *minValue, *maxValue);

            for (int i = 0; i < prices.size(); i++)
            {
                // if (prices[i] > ((*maxValue / 2) + 1))
                // {
                //     printf("Deleted i:%d\n", prices[i]);
                //     continue;
                // }
                for (int j = i; j < prices.size(); j++)
                {
                    if (((prices[j] - prices[i]) > minDelta))
                    {
                        minDelta = prices[j] - prices[i];
                        // printf("This is counted:%d, %d\n", prices[j], prices[i]);
                    }
                    if ((prices[j] - prices[i]) == *maxValue - *minValue)
                    {
                        return minDelta;
                    }
                }
            }
        }
        return minDelta;
    }
};
int main()
{
    Solution S;
    vector<int> prices = {1};
    auto result = S.maxProfit(prices);
    printf("%d", result);
}