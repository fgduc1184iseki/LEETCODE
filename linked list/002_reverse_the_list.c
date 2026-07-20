/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *first = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *temp = NULL;

    while (head != NULL)
    {
        pre = head->next;
        head->next = first;
        first = head;
        head = pre;
    }
    return first;
}