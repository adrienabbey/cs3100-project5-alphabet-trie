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
    /// represents a letter of the alphabet (i = 0 for 'a', i = 1 for 'b',
    /// etc.).  An additional index is added to represent the terminating
    /// character (i = 26 for '&').
    TrieNode *pointerArray[27];

public:
    /* Constructors */

    /// @brief Creates an empty trie node.
    TrieNode();
};