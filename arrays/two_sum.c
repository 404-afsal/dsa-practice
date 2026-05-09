/*
 * Problem: Two Sum (LeetCode #1)
 * Approach: One-pass HashMap
 * Time: O(n) | Space: O(n)
 * Pattern: HashMap - store complement and look it up as go
 * Brute force would be: O(n²) nested loops checking all pairs
 * Purpose: return indices of the two numbers such that they add up to "target"
   assuming caller calls free()
 */
#define SIZE 100

// Creating hash table
typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

node *table[SIZE];

// Hash mapping
int hash(int key)
{
    return abs(key) % SIZE;
}

// Insert key(number):value(index) to hash table
void insert(int key, int value)
{
    int index = hash(key);
    node *n = malloc(sizeof(node));
    n->key = key;
    n->value = value;
    n->next = table[index];
    table[index] = n;
}

// Search if complement for 'target - nums[i]' exists
int search(int key)
{
    int index = hash(key);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (cursor->key == key)
        {
            return cursor->value;
        }
        cursor = cursor->next;
    }
    return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    memset(table, 0, sizeof(table)); // Reset the hash table

    // Hash map: One-pass
    for (int i = 0; i < numsSize; i++)
    {
        int need = target - nums[i]; // Find the complement for 'target - nums[i]'
        int found = search(need);    // Have I seen complement before?
        if (found != -1)
        {
            if (found != i)
            { // Are the elements same?
                int *result = malloc(numsSize * sizeof(int));
                result[0] = found;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
        }
        insert(nums[i], i); // Store (number: index)
    }
    *returnSize = 0;
    return NULL;
}