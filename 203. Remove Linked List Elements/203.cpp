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
                    if (current != nullptr && ((current->next)->val != 6 && (current->next)->next != nullptr))
                    {
                        resulted->next = new ListNode();
                    }
                    resulted = resulted->next;
                }
            }
            current = current->next;
            if (current->next == nullptr)
            {
                printLinkedList(resultedHead);
                return resultedHead;
            }
        }
        return nullptr;
    }
    // ListNode *removeElements(ListNode *head, int val)
    // {
    //     if (head == nullptr)
    //     {
    //         return nullptr;
    //     }
    //     ListNode *current = head;
    //     ListNode *buffer = nullptr;
    //     while (current->next != nullptr)
    //     {

    //         if (current->val == val)
    //         {
    //             ListNode *bufferForNext = current->next;
    //             current = buffer;
    //             current->next = bufferForNext;
    //         }
    //         if (((current->next)->next) != nullptr)
    //         {
    //             if (((current->next)->next)->val == val)
    //             {
    //                 buffer = current->next;
    //             }
    //         }
    //         current = current->next;
    //     }
    //     printLinkedList(head);
    //     return head;
    // }
    void printLinkedList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        printf("\n");
        ListNode *current = head;
        while (current->next != nullptr)
        {
            printf("%d ", current->val);
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
        *removeElements(head, val);
        return head;
    }
};
int main()
{
    Solution s;
    int inp[] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    s.InitLinkedList(inp, val, (sizeof(inp) / sizeof(inp[0])));
    return 0;
}