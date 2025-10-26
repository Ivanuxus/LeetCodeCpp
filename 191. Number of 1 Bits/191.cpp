#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int hammingWeight(int n) {
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
		for (int i = 0; i < counter; i++)
		{
			if (binary[i] == 1)
			{
				resint++;
			}
		}
		return resint;

	}
};
int main()
{
	Solution S;
	cout << S.hammingWeight(2147483645);
}