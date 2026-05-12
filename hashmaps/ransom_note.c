// Problem: 383. Ransom Note
// Difficulty: Easy
// Pattern: Hashmap (Array-indexed)
// Approach: Count letter frequencies in magazine using freq[26].
//           For each letter in ransomNote, check if freq > 0 and decrement.
//           Return false immediately if any letter is missing.
// Time: O(n + m) | Space: O(1) — fixed 26-size array
#include <stdbool.h>

int hash(char key)
{
    return key - 'a';
}

bool canConstruct(char *ransomNote, char *magazine)
{
    int freq[26] = {0};
    // Map all the letters in magazine
    int lengthM = strlen(magazine);
    for (int i = 0; i < lengthM; i++)
    {
        freq[hash(magazine[i])] += 1;
    }
    // Are the letters in RN appeared in magazine?
    int lengthRN = strlen(ransomNote);
    int idx = -1;
    for (int j = 0; j < lengthRN; j++)
    {
        idx = hash(ransomNote[j]);
        if (freq[idx] == 0)
        {
            return false;
        }
        else
        {
            freq[idx] -= 1;
        }
    }
    return true;
}
