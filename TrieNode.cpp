// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#include <string>
#include "TrieNode.h"

using namespace std;

/* Constructors */

TrieNode::TrieNode()
{
    // When creating a new node, fill the pointer array with nulls:
    for (TrieNode *p : pointerArray)
    {
        p = nullptr;
    }
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

bool TrieNode::newChild(const char &character)
{
    // If a node does not already exist for the given character:
    if (findChild(character) == nullptr)
    {
        // Determine which index should be changed:
        int charIndex = character - 'a' + 1;

        // Then create a new node:
        pointerArray[charIndex] = new TrieNode();

        // New node created and added, return true:
        return true;
    }
    else
    {
        // A node already exists, do not create a new node, return false:
        return false;
    }
}