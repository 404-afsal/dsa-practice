/*
 * LeetCode #88 - Merge Sorted Array
 * Pattern: Two Pointers (Back-fill)
 * Time: O(m + n) | Space: O(1)
 */
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int x = m - 1;       // last element in nums1
    int y = n - 1;       // last element in nums2
    int i = (m + n) - 1; // last position in nums1

    while (x >= 0 && y >= 0) // Is any array empty?
    {
        if (nums1[x] > nums2[y])
        {
            nums1[i--] = nums1[x--];
        }
        else
        {
            nums1[i--] = nums2[y--];
        }
    }

    // If nums1 is empty or nums2 still has elements
    while (y >= 0)
    {
        nums1[i--] = nums2[y--];
    }
    // If nums2 is empty: do nothing; nums1 is already sorted
}