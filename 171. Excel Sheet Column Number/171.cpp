#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int titleToNumber(string columnTitle)
	{
		int result = 0;
		string a;
		char Alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		string::iterator it;
		int span = 0;
		for (it = columnTitle.end(); it != columnTitle.begin() - 1; it--)
		{
			for (int i = 0; i < 27; i++)
			{
				if (*it == Alphabet[i])
				{
					for (int j = 1; j < 27; j++)
					{
						if (i == j)
						{
							break;
						}
						span += 25;
					}
					result += (i + span);
				}
			}
		}
		return result;
	}
	int convertToTitle(string Resulted)
	{
		vector<int> result = {0, 0, 0, 0, 0, 0, 0, 0};
		int sum = 0;
		char Alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		int i = result.size() - 1;
		string a;
		while (true)
		{
			string a = "";
			auto end = result.size() - 1;
			result[end] += 1;
			if (result[end] == 27)
			{
				result[end - 1] += 1;
				sum += result[end];
				result[end] = 1;				
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
			cout << a;
			if (a == Resulted)
			{
				for (int j = 0; j < result.size(); j++)
				{
					cout << result[j] << " ";
					if(result[j] == 1){continue;}
					sum += result[j];
				}
				return sum;
			}
		}
	}
};
int main()
{
	Solution S;
	string columnTitle = "";
	cin >> columnTitle;
	// auto a = S.titleToNumber(columnTitle);
	auto a = S.convertToTitle("AB");
	cout << endl;
	cout << a;
}
