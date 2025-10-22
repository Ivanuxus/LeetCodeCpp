#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int convertToTitle(string Resulted)
	{
		vector<int> result = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int sum = 0;
		char Alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		int i = result.size() - 1;
		string a;
		while (true)
		{
			string a = "";
			auto end = result.size() - 1;
			result[end] += 1;
			sum += 1;
			for (int j = 1; j < result.size(); j++)
			{
				if (result[j] == 27)
				{
					result[j - 1] += 1;
					result[j] = 1;
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
			if (a == Resulted)
			{
				for (int j = 0; j < result.size(); j++)
				{
					cout << result[j] << " ";
				}
				cout << a;
				return sum;
			}
			else
			{
				string a = "";
			}
		}
	}
};
int main()
{
	Solution S;
	string columnTitle = "";
	// cin >> columnTitle;
	// auto a = S.titleToNumber(columnTitle);
	auto a = S.convertToTitle("FXSHRXW");
	cout << endl;
	cout << a;
}
