#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	void fillToSizeOfResulted(vector<int> &result, string &Resulted)
	{
		if (Resulted.size() - result.size() > 2)
		{
			while (Resulted.size() != result.size())
			{
				result.push_back(1);
			}
		}
	}
	string convertionFromVectorOfNumsToString(vector<int> &result, char *Alphabet)
	{
		string a = "";
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
	void makeTheSameNumber(vector<int> &result, string &Resulted, char *Alphabet)
	{
		while (true)
		{
			for (int i = 0; i < result.size(); i++)
			{
				while (Alphabet[result[i]] != Resulted[i])
				{
					result[i] += 1;
				}
			}
			break;
		}
	}
	int countNumOfRow(vector<int> &result, string &Resulted, char *Alphabet)
	{
		int i = 0;
		int num = 0;
		for (int j = 0; j < result.size(); j++)
		{
			if (result[j] != 0)
			{
				i = j;
				break;
			}
		}
		while (i < result.size() - 1)
		{
			if (result[i] > 0)
			{
				result[i + 1] += 26;
				result[i] -= 1;
			}
			if (result[i] == 0)
			{
				i++;
			}
			if (result[i] < 0)
			{
				cout << "vse ploho";
			}
			if (i >= (result.size() - 1))
			{
				break;
			}
		}
		return result[result.size() - 1];
	}

	int titleToNumber(string columnTitle)
	{
		vector<int> result = {};
		int sum = 0;
		char Alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
		if (columnTitle.size() == 1)
		{
			for (int k = 0; k < 27; k++)
			{
				if (Alphabet[k] == columnTitle[0])
				{
					return k;
				}
			}
		}
		else
		{
			fillToSizeOfResulted(result, columnTitle);
			int i = result.size() - 1;
			makeTheSameNumber(result, columnTitle, Alphabet);
			string a = convertionFromVectorOfNumsToString(result, Alphabet);
			sum = countNumOfRow(result, columnTitle, Alphabet);
			return sum;
		}
		return sum;
	}
};
int main()
{
	Solution S;
	string columnTitle = "";
	cout << S.titleToNumber("FXSHRXW");
}
