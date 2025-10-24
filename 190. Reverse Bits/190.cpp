#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
	int reverseBits(int n)
	{
		vector<int> binary = {};
		vector<int>::iterator it = binary.begin();
		int counter = 0;
		int resint = 0;
		stringstream ss;
		while (n != 0)
		{
			binary.insert(it, (n % 2));
			counter++;
			it = binary.begin() + counter;
			n /= 2;
		}
		string res;
		for (int i = binary.size() - 1; i > 0; i--)
		{
			res += binary[i];
		}
		ss << res;
		ss >> resint;
		return resint;
	}
};
int main()
{
	Solution S;
	cout << S.reverseBits(228);
}
