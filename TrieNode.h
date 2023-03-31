// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#pragma once

#include <string>

using namespace std;

class TrieNode
{
private:
    /* Fields */

    /// @brief A fixed-sized array of pointers to other nodes.  Each index
    /// represents a letter of the alphabet (i = 1 for 'a', i = 26 for 'z',
    /// etc.).  Index 0 represents the terminating character (i = 0 for '&').
    TrieNode *pointerArray[27];

public:
    /* Constructors */

    /// @brief Creates an empty trie node.
    TrieNode();

    /* Methods */

    /// @brief Checks to see if a child node exists for the given character, returning a reference to that node if it exists.
    /// @param character The character to search for.
    /// @return Returns a reference to a Trie Node if one exists for the given character.
    TrieNode *findChild(const char &character);
};