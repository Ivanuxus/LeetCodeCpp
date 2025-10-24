#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int addDigits(int num)
	{
	mark:
		vector<int> nums = {};
		int res = 0;
		while (num > 9)
		{
			nums.push_back(num % 10);
			num /= 10;
		}
		nums.push_back(num);
		num = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			num += nums[i];
		}
		if (num > 9)
		{
			goto mark;
		}
		res = num;
		return res;
	}
};
int main()
{
	Solution S;
	cout << S.addDigits(38);
}
