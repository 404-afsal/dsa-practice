/*
* 141. Linked List Cycle
* Difficulty: Easy
* Pattern: Hash Set (Address Tracking)

* Approach:
    Use a custom hash set that stores visited node memory addresses.
    For each node, check if its address is already in the set (cycle found).
    Hash by pointer address with chaining to handle collisions.

Time: O(n) | Space: O(n)
*/
#define SIZE 10007

typedef struct Node
{
    struct ListNode *memoryAdrs; /* the visited list node this wrapper tracks */
    struct Node *next;           /* next wrapper in the chain (collision handling) */
} Node;

Node *set[SIZE] = {0}; /* hash set of visited node addresses, indexed by hash */

/* hash a pointer by stripping alignment bits and folding into table size */
int hash(struct ListNode *node)
{
    int index = ((uintptr_t)node >> 3) % SIZE;
    return index;
}

/* walk the chain at node's bucket; return true if address already visited */
bool search(struct ListNode *node)
{
    int idx = hash(node);
    Node *cursor = set[idx];
    while (cursor != NULL)
    {
        if (cursor->memoryAdrs == node)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/* insert node's address into the hash set, chaining on collision */
void insert(struct ListNode *node)
{
    int idx = hash(node);
    Node *n = malloc(sizeof(Node));
    n->memoryAdrs = node;
    n->next = NULL;
    if (set[idx] != NULL)
    {
        n->next = set[idx]->next;
        set[idx]->next = n;
    }
    else
    {
        set[idx] = n;
    }
}

bool hasCycle(struct ListNode *head)
{
    memset(set, 0, sizeof(set)); /* clear set from previous test case */
    struct ListNode *curr = head;
    while (curr != NULL)
    {
        if (set[hash(curr)] != NULL)
        {
            if (search(curr))
            { /* address seen before — cycle confirmed */
                return true;
            }
        }
        insert(curr); /* mark this address as visited */
        curr = curr->next;
    }
    return false; /* reached end of list — no cycle */
}