#include <stdio.h>
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *current = head;
        ListNode *resulted = new ListNode();
        ListNode *resultedHead = resulted;
        while (current->next != nullptr)
        {
            if (current->val != val)
            {
                resulted->val = current->val;
                if (current->next != nullptr)
                {
                    if (current != nullptr)
                    {
                        resulted->next = new ListNode();
                    }
                    resulted = resulted->next;
                }
            }
            current = current->next;
            if (current->next == nullptr)
            {
                ListNode *currentx = resultedHead;
                while (currentx->next != nullptr)
                {
                    if ((currentx->next)->val == 0)
                    {
                        currentx->next = nullptr;
                        continue;
                    }
                    currentx = currentx->next;
                }
                if (resultedHead->val == 0)
                {
                    resultedHead = nullptr;
                }
                return resultedHead;
            }
        }
        return nullptr;
    }
    void printLinkedList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        printf("\n");
        ListNode *current = head;
        while (true)
        {
            printf("%d ", current->val);
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
        }
    }
    ListNode *InitLinkedList(int inp[], int &val, int count)
    {
        ListNode *current = new ListNode(inp[0], new ListNode());
        ListNode *head = current;
        current = current->next;
        for (int i = 1; i < count; i++)
        {
            *current = ListNode(inp[i], new ListNode());
            if (i + 1 < count)
            {
                current = current->next;
            }
        }
        if (count == 0)
        {
            head = nullptr;
        }
        printLinkedList(head);
        printf("\n");
        ListNode *newHead = removeElements(head, val);
        printLinkedList(newHead);
        return head;
    }
};
int main()
{
    Solution s;
    int inp[] = {1};
    int val = 2;
    s.InitLinkedList(inp, val, (sizeof(inp) / sizeof(inp[0])));
    return 0;
}