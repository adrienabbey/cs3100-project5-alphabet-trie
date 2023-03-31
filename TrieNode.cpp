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

bool TrieNode::hasTerminator()
{
    // If a terminator node does not exist:
    if (pointerArray[0] == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TrieNode::setTerminator(bool b)
{
    // If we're setting a terminator node and one does not already exist:
    if (b == true && pointerArray[0] == nullptr)
    {
        // Create a new terminator node:
        pointerArray[0] = new TrieNode();

        // Since we made changes, return true:
        return true;
    }
    // If we're removing a terminator node and one already exists:
    else if (b == false && pointerArray[0] != nullptr)
    {
        // Delete the terminator node (to avoid memory leaks):
        delete pointerArray[0];

        // Set the terminator index to null:
        pointerArray[0] = nullptr;

        // Since we made changes, return true:
        return true;
    }
    // Otherwise, we make no changes and return false:
    else
    {
        return false;
    }
}