/*
 * 1002. Find Common Characters
 * Difficulty: Easy
 * Pattern: Hash Map / Frequency Count
 *
 * Approach: Build a separate frequency hash table (size 26) for each word.
 * For each letter, find the minimum frequency across all tables —
   that minimum is how many times it appears in the common result.
 * Output one char* per occurrence.
 *
 * Time: O(n * m) | Space: O(n * 26) where n = wordsSize, m = word length
 */
#include <stdbool.h>

#define TABLE_SIZE 26

// Node struct (char: frequency)
typedef struct node
{
    char key;
    int value;
} node;

// A hash function
int hash(char key)
{
    return key - 'a';
}

// An insert function
void insert(node *table[TABLE_SIZE], char key)
{
    int idx = hash(key);
    if (table[idx] == NULL)
    {
        node *n = malloc(sizeof(node));
        table[idx] = n;
        table[idx]->key = key;
        table[idx]->value = 1;
    }
    else
    {
        table[idx]->value++;
    }
}

// A lookup function
bool search(node *table[TABLE_SIZE], char key)
{
    int idx = hash(key);
    if (table[idx] != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char **commonChars(char **words, int wordsSize, int *returnSize)
{
    // Tables for every word
    node *table[wordsSize][TABLE_SIZE];

    for (int w = 0; w < wordsSize; w++)
    {
        int len = strlen(words[w]);
        memset(table[w], 0, TABLE_SIZE * sizeof(node *));
        for (int let = 0; let < len; let++)
        {
            insert(table[w], words[w][let]);
        }
    }

    int freq[26] = {0};
    int total = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < wordsSize; j++)
        {
            if (!(search(table[j], 'a' + i)))
            {
                freq[i] = 0;
                break;
            }
            if (freq[i] > 0)
            {
                freq[i] = (table[j][i]->value > freq[i]) ? freq[i] : table[j][i]->value;
            }
            else
            {
                freq[i] = table[j][i]->value;
            }
        }
        if (freq[i] > 0)
        {
            total += freq[i];
        }
    }

    char **result = malloc(total * sizeof(char *));

    int idx = 0;
    for (int x = 0; x < 26; x++)
    {
        for (int y = 0; y < freq[x]; y++)
        {
            result[idx] = malloc(2 * sizeof(char));
            result[idx][0] = 'a' + x;
            result[idx][1] = '\0';
            idx++;
        }
    }

    *returnSize = total;
    return result;
}