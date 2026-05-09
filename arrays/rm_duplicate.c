/*
    Purpose: Remove duplicates from a sorted array of unique, non-decreasing numbers
*/
int removeDuplicates(int *nums, int numsSize)
{
    // Two pointer: Slow & Fast
    int slow = 1; // Position to write the next unique element

    for (int fast = 1; fast < numsSize; fast++)
    {
        // If found a new unique element
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast]; // Write it at the slow pointer
            slow++;                  // Move slow pointer forward
        }
    }
    return slow;
}