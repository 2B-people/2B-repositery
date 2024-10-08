#include <stdio.h>

#include <stdlib.h>

struct ListNode {
int val;
struct ListNode *next;
};

#include <stdio.h>

#include <stdlib.h>

struct ListNode {
int val;
struct ListNode *next;
};
struct ListNode* findNthFromEnd(struct ListNode* head, int n);


struct ListNode* findNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* first = head;
    struct ListNode* second = head;
    for (int i = 0; i <= n-1; i++)
    {
        first = first->next;
    }

    while (first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return second;
}
