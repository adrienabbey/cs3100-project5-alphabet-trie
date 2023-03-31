// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#include <string>
#include "TrieNode.h"

using namespace std;

/* Constructors */

TrieNode::TrieNode()
{
}

TrieNode *TrieNode::findChild(const char &character)
{
    // Convert the given character to an index value:
    int charIndex = character - 'a' + 1;

    // Check to see if the given index value has any pointers:
    TrieNode *returnPointer = pointerArray[charIndex];

    // Return the pointer to the given child, if it exists:
    return returnPointer;
}