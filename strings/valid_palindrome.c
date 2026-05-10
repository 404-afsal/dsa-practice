/*
 * 125. Valid Palindrome
 * Pattern: Two Pointers (inward)
 * Time: O(n) | Space: O(1)
 * Purpose: Check if a string is a palindrome ignoring non-alphanumeric characters
 */
bool isPalindrome(char *s)
{
    int left = 0;              // Pointer at the beginning of the string
    int right = strlen(s) - 1; // Pointer at the end

    while (left < right)
    {
        if (!isalnum(s[left]))
        { // Move left once forward if current s[left] is non-alphanumeric
            left++;
            continue;
        }
        if (!isalnum(s[right]))
        { // Move right once backward if current s[right] is non-alphanumeric
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right]))
        { // Are these same characters?
            return false;
        }
        left++;
        right--;
    }
    return true; // Default
}