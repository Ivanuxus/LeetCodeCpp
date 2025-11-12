#include <iostream>
#include <vector>
#include <string>
#include <map>
class Solution
{
    std::map<std::string, std::string> function{{"CPU", "d"}, {"GPU", "asd"}, {"RAM", "asd"}};

public:
    bool isInMap(std::string elem)
    {
        for (auto it = function.begin(); it != function.end(); ++it)
        {
            if (elem == it->first || elem == it->second)
            {
                return true;
            }
        }
        return false;
    }
    void displaceToVector(std::vector<std::string> &result, std::string s)
    {
        std::string concat = "";
        std::string::iterator it = s.begin();
        while (it != s.end())
        {
            bool subFound = false;
            while (*it != ' ')
            {
                concat += *it;
            }

            result.push_back(concat);
            concat = "";
        }
    }
    bool isInMap(char ch)
    {
        std::string elem = "";
        elem.push_back(ch);
        for (auto it = function.begin(); it != function.end(); ++it)
        {
            if (elem == it->first || elem == it->second)
            {
                return true;
            }
        }
        return false;
    }
    bool wordPattern(std::string pattern, std::string s)
    {
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (!isInMap(pattern[i]))
            {
            }
        }
        return true;
    }
};
int main()
{
    std::vector<std::string> Displaced = {};
    std::string s = "BS as sdnj";
    Solution S;
    S.displaceToVector(Displaced, s);
    return 0;
}