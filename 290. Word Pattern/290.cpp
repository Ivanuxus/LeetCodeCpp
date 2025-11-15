#include <iostream>
#include <vector>
#include <string>
#include <map>
class Solution
{
    std::map<std::string, std::string> function{};

public:
    bool isInMapValues(std::string elem)
    {
        for (auto it = function.begin(); it != function.end(); ++it)
        {
            if (elem == it->second)
            {
                return true;
            }
        }
        return false;
    }
    bool isInMapKeys(char ch)
    {
        std::string elem = "";
        elem.push_back(ch);
        for (auto it = function.begin(); it != function.end(); ++it)
        {
            if (elem == it->first)
            {
                return true;
            }
        }
        return false;
    }
    std::vector<std::string> splitToVector(std::string s)
    {
        std::vector<std::string> result = {};
        std::cout << std::endl;
        std::string concat = "";
        int i = 0;
        while (i < s.size())
        {
            bool subFound = false;
            while (s[i] != ' ' && i != s.size())
            {
                subFound = true;
                concat += s[i];
                i++;
            }
            if (subFound)
            {
                result.push_back(concat);
                subFound = false;
                concat = "";
            }
            i++;
        }
        return result;
    }
    bool wordPattern(std::string pattern, std::string s)
    {
        std::vector<std::string> splittedString = splitToVector(s);
        for (int i = 0; i < splittedString.size(); ++i)
        {
            if (!isInMapKeys(pattern[i]) && isInMapValues(splittedString[i]))
            {
                return false;
            }
            else if (isInMapValues(splittedString[i]) && isInMapKeys(pattern[i]))
            {
                std::string tempS(1, pattern[i]);
                if (function[tempS] == splittedString[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if (!isInMapValues(splittedString[i]) && isInMapKeys(pattern[i]))
            {
                return false;
            }
            else if (!isInMapValues(splittedString[i]) && !isInMapKeys(pattern[i]))
            {
                std::string tempS(1, pattern[i]);
                function[tempS] = splittedString[i];
            }
        }
        return true;
    }
};
int main()
{
    std::string pattern = "abc";
    std::string s = "b c a";
    Solution S;
    std::cout << S.wordPattern(pattern, s);
    return 0;
}