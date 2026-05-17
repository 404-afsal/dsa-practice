/*
 * 203. Remove Linked List Elements
 * Difficulty: Easy
 * Pattern: Linked List Traversal / Two Pointer (prev-curr)

 * Approach:
        Skip leading nodes equal to val to establish a clean return head.
        Traverse with prev and curr pointers; on a match, bypass the node
        by linking prev->next to curr->next, otherwise advance prev.

 * Time: O(n) | Space: O(1)
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *ReturnHead = head;

    // Skip leading nodes that equal val
    while (ReturnHead != NULL && ReturnHead->val == val)
    {
        ReturnHead = ReturnHead->next;
    }

    // Entire list was val
    if (ReturnHead == NULL)
    {
        return ReturnHead;
    }

    struct ListNode *curr = ReturnHead;
    struct ListNode *prev = NULL;

    while (curr != NULL)
    {
        if (curr->val == val)
        {
            // Bypass curr
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return ReturnHead;
}