// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#include <string>
#include "Trie.h"

using namespace std;

/* Constructors */

Trie::Trie()
{
    // An empty trie has no root node:
    root = nullptr;
}

Trie::Trie(const Trie &other)
{
}

/* Methods */

bool Trie::insert(string word)
{
    // Start at the root node:
    TrieNode *currentNode = root;

    // For each character in the word:
    for (char &c : word)
    {
        // If the character is not a child:
        // Add a new child node for that character:
        // Otherwise, move to the child node of the character:
    }

    // If there is no terminating node:
    // Add a new terminating node:
    // Since we added a new terminating node, the insert was successful, return true:
    // If we did not insert a terminating node, the insert was NOT successful; return false:
}

int Trie::count()
{
}

int Trie::getSize()
{
}

bool Trie::find(string word)
{
}

int Trie::completeCount(string partialWord)
{
}

vector<string> Trie::complete(string partialWord)
{
}

/* Overrides */

Trie &Trie::operator=(const Trie &other)
{
}