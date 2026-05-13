// Problem: 349. Intersection of Two Arrays
// Difficulty: Easy
// Pattern: Hash Set (Direct Address)
// Approach: Store nums1 values in a boolean set. Walk nums2 and mark matches
//            in a result set, using set[idx] = false to prevent duplicates.
//           Build result by scanning result set.
// Time: O(n + m) | Space: O(1) — fixed 1001-element arrays
#include <stdbool.h>

#define MAX_VAL 1001

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    bool set[1001] = {false};
    int idx = -1;
    int resultSize = 0;
    // Mark all numbers in nums1
    for (int i = 0; i < nums1Size; i++)
    {
        idx = nums1[i];
        if (!set[idx])
        {
            set[idx] = true;
        }
    }
    // Mark the actual intersections based on the set
    bool resultSet[1001] = {false};
    for (int i = 0; i < nums2Size; i++)
    {
        idx = nums2[i];
        if (set[idx])
        {
            resultSize++;
            resultSet[idx] = true;
            set[idx] = false;
        }
    }
    int *result = malloc(resultSize * sizeof(int));
    int pos = 0;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (resultSet[i])
        {
            result[pos] = i;
            pos++;
        }
    }
    *returnSize = resultSize;
    return result;
}