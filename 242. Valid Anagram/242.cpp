#include <iostream>
#include <string>
#include <map>
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::map<std::string, int> a = Mapper(s);
        std::map<std::string, int> b = Mapper(t);
        return mapCompare(a, b);
    }
    std::map<std::string, int> Mapper(std::string s)
    {
        std::map<std::string, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            bool exist = false;
            int counter = 0;
            std::string str;
            for (auto it = m.begin(); it != m.end(); ++it)
            {
                str.push_back(s[i]);
                if (it->first == str)
                {
                    exist = true;
                    it->second += 1;
                }
                str.erase();
            }
            if (!exist)
            {
                str.erase();
                str.push_back(s[i]);
                m[str] = 1;
                str.erase();
                exist = false;
            }
        }
        return m;
    }
    bool mapCompare(std::map<std::string, int> &m1, std::map<std::string, int> &m2)
    {
        int counter = 0;
        for (auto it1 = m1.begin(); it1 != m1.end(); ++it1)
        {
            bool result = false;
            for (auto it2 = m2.begin(); it2 != m2.end(); ++it2)
            {
                if (((it1->first == it2->first) && (it1->second == it2->second)))
                {
                    result = true;
                    counter++;
                }
            }
        }
        int size;
        if (m1.size() > m2.size())
        {
            size = m1.size();
        }
        else
        {
            size = m2.size();
        }
        if (counter == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution s;
    std::cout << "\n"
              << s.isAnagram("nagaram", "anagramm");
}