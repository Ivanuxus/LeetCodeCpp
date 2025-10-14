#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> nodes = {};
        ListNode *current = head;
        while (current != nullptr)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if ((current->next) == nodes[i])
                {
                    return true;
                }
            }

            // printf("%ds ", current->val);
            nodes.push_back(current->next);
            current = current->next;
        }

        return false;
    }
    ListNode *createListFromMassive(vector<int> &nums)
    {
        int n = nums.size();
        ListNode *current = new ListNode(nums[0]);
        ListNode *listHead = current;

        for (int i = 1; i < n; i++)
        {
            current->next = new ListNode(nums[i]);
            current = current->next;
        }
        // Make a loop before return
        current->next = listHead;
        //
        return listHead;
    }

    void print(ListNode *listHead)
    {
        ListNode *current = listHead;
        while (current != nullptr)
        {
            printf("%ds ", current->val);
            current = current->next;
        }
    }

    void deleteList(ListNode *listHead)
    {
        ListNode *current = listHead;
        while (current != nullptr)
        {
            ListNode *next = current;
            delete current;
            current = next;
        }
    }
};

int main()
{
    Solution S;
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution::ListNode *result = S.createListFromMassive(nums);
    // S.print(result);
    // printf("\n");
    cout << S.hasCycle(result);
    S.deleteList(result);
}