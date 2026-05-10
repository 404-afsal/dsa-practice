/*
 * 242. Valid Anagram
 * Pattern: Frequency Count (Hash Map)
 * Time: O(n) | Space: O(1) — fixed 26-char alphabet
 * Problem: Check if string t is an anagram for string s
 */

#define SIZE 26

typedef struct
{
    char key;
    int value;
} freq;

freq table[2][SIZE]; // Hash map for char:frequency

// Hash to map
int hash(char key)
{
    return key - 'a';
}

// Insert char:frequency / frequency to map
void insert(freq table[SIZE], char key)
{
    int index = hash(key);
    table[index].key = key;
    table[index].value++;
}

bool isAnagram(char *s, char *t);

int main(void)
{
    char s[] = {"hello"};
    char t[] = {"oeehl"};
    isAnagram(s, t);
}

bool isAnagram(char *s, char *t)
{
    memset(table, 0, sizeof(table));
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS == lenT)
    {
        int i = 0; // Position in s
        while (i < lenS)
        {
            insert(table[0], s[i++]);
        }
        int j = 0; // Position in t
        while (j < lenT)
        {
            // Is the current char in t exist in s?
            if (table[0][hash(t[j])].value == 0)
            {
                return false;
            }
            insert(table[1], t[j]);
            // Does the frequency of current char in t higher than in s?
            if (table[1][hash(t[j])].value > table[0][hash(t[j])].value)
            {
                return false;
            }
            j++;
        }
    }
    else
    {
        return false;
    }
    return true;
}