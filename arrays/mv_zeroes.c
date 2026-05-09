/*
 * Problem: Move Zeroes (LeetCode#283)
 * Approach: Two Pointers - slow/fast with swap
 * Time: O(n) | Space: O(1)
 * Pattern: Two Pointers - slow tracks write position,
 *           fast scans for non-zero elements
 * Brute force would be: O(n²) shifting elements left on each zero found
 * Purpose: Move all 0's to the end of the array while maintaining the relative order of the non-zero elements.
 */
void moveZeroes(int *nums, int numsSize)
{
    // Two pointer: Slow & Fast
    int slow = 0; // Position to write the next non-zero element

    for (int fast = 0; fast < numsSize; fast++)
    {
        // If found a non-zero element
        if (nums[fast] != 0)
        {
            // Swap 0 with no-zero
            int tmp = nums[slow];
            nums[slow] = nums[fast]; // Write it at the slow pointer
            nums[fast] = tmp;
            slow++; // Move slow pointer forward
        }
    }
}