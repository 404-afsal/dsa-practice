/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Pattern: Fast & Slow Pointers (Floyd's Cycle Detection)
 *
 * Approach:
        Use two pointers moving at different speeds through the list.
        If a cycle exists, the fast pointer will eventually lap the slow one
        and they will meet at the same node.
 *
 * Time: O(n) | Space: O(1)
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {                            // fast needs two steps, so check both
        slow = slow->next;       // tortoise: one step
        fast = fast->next->next; // hare: two steps
        if (slow == fast)
        { // pointers met — cycle confirmed
            return true;
        }
    }
    return false; // fast hit end — no cycle
}