#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int reverseBits(int n)
	{
		vector<int> binary = {};
		vector<int>::iterator it = binary.begin();
		int counter = 0;
		while (n != 0)
		{
			binary.insert(it, (n % 2));
			counter++;
			it = binary.begin() + counter;
			n /= 2;
		}
		string res = "";
		for (vector<int>::iterator it = binary.end() - 1; it != binary.begin(); it--)
		{
			string s = *it;
			res = res + s;
		}
		cout << res;
		// n = stoi(res);
		return n;
	}
};
int main()
{
	Solution S;
	cout << S.reverseBits(228);
}
