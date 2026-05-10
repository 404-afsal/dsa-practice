/*
 * 344. Reverse String
 * Pattern: Two Pointers (inward)
 * Time: O(n) | Space: O(1)
 * Purpose: Reverse a string
 */
void reverseString(char *s, int sSize)
{
    // Two pointer: moving towards each other
    int x = 0;         // Pointer at the beginning
    int y = sSize - 1; // Pointer at the end

    for (int i = 0; i < (sSize / 2); i++)
    {
        // Swap characters with pointers as moving
        char c = s[y];
        s[y--] = s[x];
        s[x++] = c;
    }
}