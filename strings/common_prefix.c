/*
 * 14. Longest Common Prefix
 * Pattern: String Traversal | Shrinking Prefix
 * Time: O(n*m) | Space: O(m)
 * Purpose: Find longest common prefix among array of strings
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    char *prefix = malloc(strlen(strs[0]) + 1);
    strcpy(prefix, strs[0]); // Assume the 1st string is prefix
    for (int i = 1; i < strsSize; i++)
    {
        int prefixSize = strlen(prefix);
        int j = 0;
        while (j < prefixSize && (strs[i][j]) == prefix[j])
        { // Checking if there are same letters
            j++;
        }
        prefix[j] = '\0'; // Cut the rest if it needs
    }
    return prefix;
}