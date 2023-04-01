// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#pragma once

#include <string>
#include <vector>
#include "TrieNode.h"

using namespace std;

class Trie
{
private:
    /* Fields */
    TrieNode *root;
    long nodeCount;
    int wordCount;

public:
    /* Constructors */

    /// @brief Creates an empty trie.
    Trie();

    /// @brief Constructor: Creates a deep copy of the given trie.
    /// @param other A reference to the other trie to be copied.
    Trie(const Trie &other);

    /* Methods */

    /// @brief Inserts a new word into the tree.  Duplicate words are not
    /// allowed.  This function should return true if the word is successfully
    /// inserted into the trie, and false if the word could not be inserted (
    /// for example, due to a duplicate word already found int he trie).
    /// @param word A string of the word to be inserted.
    /// @return True if successful, false if not.
    bool insert(string word);

    /// @brief Returns the number of words in the trie.
    /// @return Number of items in the trie.
    int count();

    /// @brief Returns the total nujmber of nodes in the trie.
    /// @return Number of nodes in the trie.
    int getSize();

    /// @brief If the given word is found in the trie, thsi function should
    /// return true.  Otherwise, this function should return false.
    /// @param word A string of the word to search for.
    /// @return True if the word is found, false if not.
    bool find(string word);

    /// @brief Returns the number of words in the dictionary that begin with
    /// the given input string.  If not matching words are found, the function
    /// should return zero.
    /// @param partialWord A string of the first part of a partial word to
    /// search for.
    /// @return Number of words that start with the given string.
    int completeCount(string partialWord);

    /// @brief Returns a vector of strings containing all the words of the
    /// dictionary that with the given input string.  For each word found in
    // the trie, there will be one value in the vector.  If no matching words
    /// are found, the function should return an empty vector.
    /// @param partialWord A string of the partial word to be searched for.
    /// @return A vector of strings containing all the words found.
    vector<string> complete(string partialWord);

    /* Overrides */

    /// @brief Removes all the contents of this trie (without memory leaks)
    /// and make a deep copy of the other trie into this trie.
    /// @param other A reference to the second trie.
    /// @return Returns a reference to this trie.
    Trie &operator=(const Trie &other);
};