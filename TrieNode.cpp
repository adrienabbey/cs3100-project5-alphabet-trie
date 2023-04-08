// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#include <string>
#include <vector>
#include "TrieNode.h"

using namespace std;

/* Constructors */

TrieNode::TrieNode()
{
    // When creating a new node, fill the pointer array with nulls:
    for (int i = 0; i < 27; i++)
    {
        pointerArray[i] = nullptr;
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

void TrieNode::completeHelper(string partialWord, vector<string> &stringVector)
{
    // This is a recursive function.

    // If this node has a terminator node:
    if (pointerArray[0] != nullptr)
    {
        // Then add the current partial word to the string vector:
        stringVector.push_back(partialWord);
    }

    // For each child (excluding terminator node):
    for (int i = 1; i < 27; i++)
    {
        // If the child exists:
        if (pointerArray[i] != nullptr)
        {
            // Add the node's character value to a string:
            char letter = 'a' + i - 1;
            string newString = partialWord; // https://stackoverflow.com/a/4751624
            newString += letter;            // https://stackoverflow.com/a/1472075

            // Then recursively call this function on the child with the given:
            TrieNode *childNode = pointerArray[i];
            childNode->completeHelper(newString, stringVector);
        }
    }
}

TrieNode *TrieNode::copyHelper(const TrieNode *originalNode)
{
    // NOTE: Never assume that 'this' node exists!

    // Create a new TrieNode to return:
    TrieNode *copyNode = new TrieNode();

    // For each child node of the original node:
    for (int i = 0; i < 27; i++)
    {
        // If a child node exists:
        if (originalNode->pointerArray[i] != nullptr)
        {
            // Recursively create a deep copy of the child:
            copyNode->pointerArray[i] = copyHelper(originalNode->pointerArray[i]);
        }
    }

    // Return the new deep copy:
    return copyNode;
}