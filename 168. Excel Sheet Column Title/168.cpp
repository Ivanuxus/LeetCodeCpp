#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string convertToTitle(int columnNumber)
	{

		vector<int> result = {0, 0, 0, 0, 0, 0, 0, 0};
		string a;
		result.push_back(columnNumber);
		char Alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		int i = result.size() - 1;
		cout << endl;
		while (i != 0)
		{
			if (result[i] / 27 > 0)
			{
				result[i] -= 26;
				result[i - 1] += 1;
			}
			if (result[i] < 27)
			{
				i--;
			}
			if (i <= 0)
			{
				break;
			}
		}
		for (int j = 0; j < result.size(); j++)
		{
			for (int k = 0; k < 27; k++)
			{
				if (k == result[j] && result[j] != 0)
				{
					a += Alphabet[k];
				}
			}
		}
		return a;
	}
};
int main()
{
	Solution S;
	int columnNumber;
	scanf("%d", &columnNumber);
	auto a = S.convertToTitle(columnNumber);
	cout << a;
}
