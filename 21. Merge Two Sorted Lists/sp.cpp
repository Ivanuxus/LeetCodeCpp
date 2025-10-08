#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        ListNode *Final = new ListNode();
        ListNode *HeadOfFinal = Final;
        ListNode *currentF = list1;
        ListNode *currentS = list2;
        while (currentF != nullptr && currentS != nullptr)
        {
            if (currentF->val >= currentS->val)
            {
                Final->val = currentS->val;
                Final->next = new ListNode(currentF->val);
            }
            else
            {
                Final->val = currentF->val;
                Final->next = new ListNode(currentS->val);
            }
            currentF = currentF->next;
            currentS = currentS->next;
            Final = Final->next;
            if (currentF == nullptr && currentS == nullptr)
            {
                break;
            }
            Final->next = new ListNode();
            Final = Final->next;
        }
        // second
        while (currentF != nullptr && currentS == nullptr)
        {
            Final->val = currentF->val;
            // Final->next = new ListNode();
            currentF = currentF->next;
            Final = Final->next;
            if (currentF == nullptr && currentS == nullptr)
            {
                break;
            }
            Final->next = new ListNode();
            Final = Final->next;
        }
        // third
        while (currentF == nullptr && currentS != nullptr)
        {
            Final->val = currentS->val;
            if (currentF == nullptr && currentS == nullptr)
            {
                break;
            }
            Final->next = new ListNode();
            currentF = currentS->next;
            Final = Final->next;
            if (currentF == nullptr && currentS == nullptr)
            {
                break;
            }
            Final->next = new ListNode();
            Final = Final->next;
        }
        cout << endl;
        while (HeadOfFinal != nullptr)
        {
            cout << HeadOfFinal->val << " ";
            HeadOfFinal = HeadOfFinal->next;
        }
        return HeadOfFinal;
    }

    ListNode *
    CreateTwoLists(vector<int> a, int aLen, vector<int> b, int bLen)
    {
        ListNode *list1 = new ListNode();
        ListNode *list2 = new ListNode();
        bool existenseOf1 = true;
        bool existenseOf2 = true;
        if (aLen == 0)
        {
            existenseOf1 = false;
            list1 = nullptr;
        }
        if (bLen == 0)
        {
            existenseOf2 = false;
            list2 = nullptr;
        }
        if (existenseOf1)
        {
            ListNode *current1 = list1;

            for (int i = 0; i < aLen; i++)
            {
                if (i == 0 && aLen != 0)
                {
                    current1->val = a[0];
                }
                else
                {
                    current1->next = new ListNode(a[i]);
                }
                current1 = current1->next;
            }
            current1 = list1;
            cout << "First: ";
            for (int i; i < aLen; i++)
            {
                cout << current1->val << " ";
                current1 = current1->next;
            }
        }
        if (existenseOf2)
        {
            ListNode *current2 = list2;

            for (int i = 0; i < bLen; i++)
            {
                current2->next = new ListNode(b[i]);
                current2 = current2->next;
            }
            current2 = list2;
            cout << endl
                 << "Second: ";
            for (int i; i < bLen; i++)
            {
                cout << current2->val << " ";
                current2 = current2->next;
            }
        }

        mergeTwoLists(list1, list2);
        return list1;
    }
};
int main()
{
    Solution S;
    vector<int> a = {};
    vector<int> b = {0};
    // int a[1] = {1};
    // int b[0] = {};
    // int lenA = sizeof(a) / sizeof(a[0]);
    // int lenB = sizeof(b) / sizeof(b[0]);
    int aLen = a.size();
    int bLen = b.size();
    S.CreateTwoLists(a, aLen, b, bLen);
    return 0;
}