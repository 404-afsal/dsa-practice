/*
 * 217. Contains Duplicate
 * Difficulty: Easy
 * Pattern: Custom Hashmap (Chaining)
 *
 * Approach:
 * Built a hashmap from scratch using a prime-sized bucket array (100003)
   with chaining for collision handling. For each element, search the
   hashmap first — if found return true, otherwise insert and continue.
 *
 * Time: O(n) | Space: O(n)
 */

#define TABLE_SIZE 100003

// Node struct(key + chaining)
typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

// A bucket array of size 100003(prime near 10^5)
node *table[TABLE_SIZE];

// A hash function
int hash(int key)
{
    return abs(key) % TABLE_SIZE;
}

// An insert function
void insert(int key)
{
    int index = hash(key);
    node *n = malloc(sizeof(node));
    n->key = key;
    n->value = 1;
    n->next = table[index];
    table[index] = n;
}

// A lookup function
bool search(int key)
{
    int index = hash(key);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (cursor->key == key)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

bool containsDuplicate(int *nums, int numsSize)
{
    memset(table, 0, sizeof(table));
    for (int i = 0; i < numsSize; i++)
    {
        if (search(nums[i]))
        {
            return true;
        }
        else
        {
            insert(nums[i]);
        }
    }
    return false;
}