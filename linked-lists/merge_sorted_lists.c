/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Pattern: Two Pointers / Linked List Merge
 *
 * Approach:
 * Pick the smaller head as resultHead and advance that list.
 * Walk both lists simultaneously, always linking the smaller node to curr.
 * After one list is exhausted, attach the remaining list directly.
 *
 * Time: O(n + m) | Space: O(1)
 */

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // Base cases: if either list is empty, return the other
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }

    // Pick the smaller head as the result head and advance that pointer
    struct ListNode *resultHead = (list1->val < list2->val) ? list1 : list2;
    if (list1->val < list2->val)
    {
        list1 = list1->next;
    }
    else
    {
        list2 = list2->next;
    }

    struct ListNode *curr = resultHead;

    // Merge while both lists have nodes
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    // Attach the remaining nodes of whichever list is not exhausted
    if (list1 == NULL)
    {
        curr->next = list2;
    }
    else
    {
        curr->next = list1;
    }

    return resultHead;
}