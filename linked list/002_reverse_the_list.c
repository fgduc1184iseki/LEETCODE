/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *will = NULL;
    struct ListNode *pre = NULL;
    while (head != NULL)
    {
        will = head->next;
        head->next = pre;
        pre = head;
        head = will;
    }
    return pre;
}