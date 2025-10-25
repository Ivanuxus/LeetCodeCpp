#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int reverseBits(int n)
	{
		unsigned long long grade = 1;
		vector<int> binary = {};
		vector<int>::iterator it = binary.begin();
		int counter = 0;
		int resint = 0;
		while (n != 0)
		{
			binary.insert(it, (n % 2));
			counter++;
			it = binary.begin() + counter;
			n /= 2;
		}
		while (counter != 32)
		{
			binary.push_back(0);
			counter++;
		}

		int res = 0;
		for (int i = 31; i >= 0; i--)
		{
			res += binary[i] * grade;
			grade *= 2;
		}
		return res;
	}
};
int main()
{
	Solution S;
	cout << S.reverseBits(43261596);
}