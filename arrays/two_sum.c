/*
 * Purpose: return indices of the two numbers such that they add up to "target"
 * assuming caller calls free()
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    // Brute force: check all pairs O(n²)
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                // Found the pair – allocate and return
                int *result = malloc(2 * sizeof(int));
                *returnSize = 2; // Tell caller array length
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}