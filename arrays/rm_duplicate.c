/*
 * Problem: Remove Duplicates from Sorted Array (LeetCode #26)
 * Approach: Two Pointers - slow/fast
 * Time: O(n) | Space: O(1)
 * Pattern: Two Pointers - slow pointer tracks write position,
 *           fast pointer scans ahead
 * Brute force would be: O(n²) shifting elements on each duplicate found
 * Purpose: Remove duplicates from a sorted array of unique, non-decreasing numbers
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