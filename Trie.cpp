// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

#include <string>
#include "Trie.h"

using namespace std;

/* Constructors */

Trie::Trie()
{
    // An empty trie has a single root node:
    root = new TrieNode();
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
        // Find the child node for the given character, if any:
        TrieNode *childNode = currentNode->findChild(c);

        // If the character node does not exist:
        if (childNode == nullptr)
        {
            // Add a new child node for that character:
            currentNode->newChild(c);
        }

        // Move to the child node of the character:
        currentNode = currentNode->findChild(c);
    }

    // If there is no terminating node:
    if (!currentNode->hasTerminator())
    {
        // Add a new terminating node:
        currentNode->setTerminator(true);

        // Since we added a new terminating node, the insert was successful, return true:
        return true;
    }

    // If we did not insert a terminating node, the insert was NOT successful; return false:
    return false;
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