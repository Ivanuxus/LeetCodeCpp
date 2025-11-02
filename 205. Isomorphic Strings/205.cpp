#include <stdio.h>
#include <string>
#include <typeinfo>
class Solution
{
public:
    struct Mapper
    {
        char FirstSymb;
        char SecondSymb;
        Mapper *next;
        Mapper() : FirstSymb(' '), SecondSymb(' '), next(nullptr) {}
        Mapper(char a, char b) : FirstSymb(a), SecondSymb(b), next(nullptr) {}
        Mapper(char a, char b, Mapper *next) : FirstSymb(a), SecondSymb(b), next(next) {}
    };
    Mapper *InsertStrToStruct(std::string s, std::string t)
    {
        Mapper *current = new Mapper();
        Mapper *head = current;
        for (int i = 0; i < s.size(); i++)
        {
            *current = Mapper(s[i], t[i]);
            if (i + 1 < s.size())
            {
                current->next = new Mapper();
                current = current->next;
            }
        }
        return head;
    }
    bool CheckForIsomorphic(Mapper *head)
    {
        Mapper *current = head;
        Mapper *current1 = head->next;
        while (true)
        {
            if (current == nullptr)
            {
                break;
            }
            while (true)
            {
                if (current1 == nullptr)
                {
                    break;
                }
                if ((current->FirstSymb != current1->FirstSymb) && ((current->SecondSymb == current1->SecondSymb)))
                {
                    return false;
                }
                if ((current->FirstSymb == current1->FirstSymb) && ((current->SecondSymb != current1->SecondSymb)))
                {
                    return false;
                }
                if (current1->next == nullptr)
                {
                    if (current == nullptr)
                    {
                        break;
                    }
                    current1 = current->next;
                    break;
                }
                current1 = current1->next;
            }
            if (current == nullptr)
            {
                break;
            }
            current = current->next;
        }
        return true;
    }
    bool checkForAvailability(Mapper *head, char s, char t)
    {
        Mapper *current = head;
        bool sInStruct = false;
        bool tInStruct = false;
        while (true)
        {
            if ((current->FirstSymb) == s)
            {
                sInStruct = true;
            }
            if ((current->SecondSymb) == t)
            {
                tInStruct = true;
            }
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
        }
        if ((sInStruct == false) && (tInStruct == true) || (sInStruct == true) && (tInStruct == false))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool isIsomorphic(std::string s, std::string t)
    {
        Mapper *FilledMapper = InsertStrToStruct(s, t);
        return CheckForIsomorphic(FilledMapper);
    }
};
int main()
{
    std::string s("foo");
    std::string t("bar");
    Solution S;
    printf("%d", S.isIsomorphic(s, t));
    return 0;
}