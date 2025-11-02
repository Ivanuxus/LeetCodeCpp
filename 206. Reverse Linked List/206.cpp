#include <stdio.h>
#include <vector>
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *resultedList = new ListNode();
        std::vector<ListNode *> nodes;
        ListNode *headOfList = resultedList;
        while (true)
        {
            nodes.push_back(head);
            head = head->next;
            if (head == nullptr)
            {
                break;
            }
            if (head->next == nullptr)
            {
                nodes.push_back(head);
                break;
            }
        }
        for (int i = nodes.size() - 1; i >= 0; i--)
        {
            resultedList->val = nodes[i]->val;
            if (i - 1 >= 0)
            {
                resultedList->next = new ListNode();
            }
            resultedList = resultedList->next;
        }
        return headOfList;
    };
    ListNode *initList(int a[], int size)
    {
        ListNode *resList = new ListNode();
        ListNode *headOfList = resList;
        for (int i = 0; i < size; i++)
        {
            resList->val = a[i];
            if ((i + 1) < size)
            {
                resList->next = new ListNode();
            }
            resList = resList->next;
        }
        return headOfList;
    };
};
int main()
{
    int a[] = {1};
    Solution s;
    s.reverseList(s.initList(a, (sizeof(a) / sizeof(a[0]))));
    return 0;
}