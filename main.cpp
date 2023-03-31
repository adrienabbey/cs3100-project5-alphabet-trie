// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

/*
 * Notes:
 *  - Since we are provided dictionaries to work with, I'm going to assume
 *    that we're ONLY working with 26 lowercase letters plus a terminating
 *    'character'.  This means not only no capital letters, but also no
 *    punctuation or other characters.
 */

#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
    // Char test:
    char testChar = 'a';
    int charInt = testChar - 'a' + 1;
    cout << "Character " << testChar << "'s int value is: " << charInt << endl;

    // Create an empty trie:
    Trie *testTrie = new Trie();

    // Insert test:
    testTrie->insert("hello");

    // Load the appropriate dictionary into a trie:
    // NOTE: See OneNote!

    return 0;
}