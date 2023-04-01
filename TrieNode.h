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

    /// @brief Checks to see if a child node exists for the given character,
    /// returning a reference to that node if it exists.
    /// @param character The character to search for.
    /// @return Returns a reference to a Trie Node if one exists for the given
    /// character, or returns nullptr if none exists.
    TrieNode *findChild(const char &character);

    /// @brief Checks to see if the trie node has a terminating node.
    /// @return Returns 'true' if a terminating node exists, 'false' if not.
    bool hasTerminator();

    /// @brief Allows the creation of a terminator node (for this node), or
    /// removes the terminator node if it already exists.
    /// @param b If 'true' and no terminator node exists, it creates one.  If
    /// 'false' and a terminator node exists, it deletes it.
    /// @return Returns true if a change to the terminator node occurred,
    /// 'false' if no change was made.
    bool setTerminator(bool b);

    /// @brief Creates a new child node for the given character, if possible.
    /// If a child node for the given character already exists, it will fail
    /// to create a new node and return 'false'.
    /// @param character A character representing the index for which a node
    /// should be created.
    /// @return Returns 'true' if a new node was created and inserted, and '
    /// false' if a node already exists and no node was created.
    bool newChild(const char &character);

    /// @brief Searches children nodes for complete words, starting at the
    /// specified node with a partial word (if any), pushing those words to
    /// the specified string vector.
    /// @param partialWord A string to prepend to every word found in the trie.
    /// @param stringVector A reference to an existing string vector, to which
    /// any found words will be pushed to.
    void completeHelper(string partialWord, vector<string> &stringVector);
};