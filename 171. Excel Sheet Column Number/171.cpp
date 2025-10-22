#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int convertToTitle(string columnTitle)
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
};
int main()
{
	Solution S;
	string columnTitle = "";
	cin >> columnTitle;
	auto a = S.convertToTitle(columnTitle);
	cout << endl;
	cout << a;
}
