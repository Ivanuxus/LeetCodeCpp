#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
		vector<int> result = {};
		string a;
		result.push_back(columnNumber);
		char Alphabet[27] = {' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};				        
		vector<int>::iterator it1 = result.end();
		vector<int>::iterator it2;
		while(it1 != result.begin()) {
			bool isFirst = true;
			if(*it1 / 27 > 0) {
				*it1 -= 26;
				if(isFirst){
					it2 = result.begin();
					result.insert(it2, 0);
					isFirst = false;
				}
				*(it1 - 1) += 1;
				
			}
			if(*it1 < 27) {
				it1--;
			}
			if(it1 == result.begin())
			{break;}
		}
		for(int j = 0; j < result.size(); j++) {
			for(int k = 0; k < 27; k++) {
		if(k == result[j] && result[j] != 0) {
				a+= Alphabet[k];
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
	cout<<a;
}
