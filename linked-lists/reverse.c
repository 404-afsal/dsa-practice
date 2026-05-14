/*
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Pattern: Linked List / Iterative Pointer Reversal
 *
 * Approach:
 * Use three pointers: prev (starts NULL), curr (starts at head), and tmp.
 * At each step, save curr->next in tmp, reverse the link, then advance both pointers.
 * When curr hits NULL, prev is the new head.
 *
 * Time: O(n) | Space: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *tmp;

    while (curr != NULL)
    {
        tmp = curr->next;  // Save next node
        curr->next = prev; // Reverse the link
        prev = curr;
        curr = tmp; // Advance
    }
    return prev;
}