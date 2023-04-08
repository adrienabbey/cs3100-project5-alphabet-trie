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

    // Tries starts with a single root node, so the initial node count is zero:
    nodeCount = 1;

    // An empty trie starts with zero words:
    wordCount = 0;
}

Trie::~Trie()
{
    // Recursively delete all the nodes in this tree, starting with the root node:
    delete root;

    // Set root to null:
    root = nullptr;

    // Zero the counters:
    nodeCount = 0;
    wordCount = 0;
}

Trie::Trie(const Trie &other)
{
    // Recursively create a deep copy of the original's root node:
    root = root->copyHelper(other.root);

    // Copy the word and node counters:
    nodeCount = other.nodeCount;
    wordCount = other.wordCount;
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

            // Increment the node counter:
            nodeCount++;
        }

        // Move to the child node of the character:
        currentNode = currentNode->findChild(c);
    }

    // If there is no terminating node:
    if (!currentNode->hasTerminator())
    {
        // Add a new terminating node:
        currentNode->setTerminator(true);

        // Increment the node count:
        nodeCount++;

        // Increment the trie's word count:
        wordCount++;

        // Since we added a new terminating node, the insert was successful, return true:
        return true;
    }

    // If we did not insert a terminating node, the insert was NOT successful; return false:
    return false;
}

int Trie::count()
{
    return wordCount;
}

int Trie::getSize()
{
    return nodeCount;
}

TrieNode *Trie::findHelper(string word)
{
    // Start at the root node:
    TrieNode *currentNode = root;

    // For each character in the word:
    for (char c : word)
    {
        // If that character does not exist:
        if (currentNode->findChild(c) == nullptr)
        {
            // Return a nullptr:
            currentNode = nullptr;
            return currentNode;
        }
        else
        {
            // Otherwise, move to the next character:
            currentNode = currentNode->findChild(c);
        }
    }

    // We found the given word, return a reference to it:
    return currentNode;
}

bool Trie::find(string word)
{
    // Start at the root node:
    TrieNode *currentNode = findHelper(word);

    // If the returned node is nullptr, return false:
    if (currentNode == nullptr)
    {
        return false;
    }

    // If the current node has a terminating character:
    if (currentNode->hasTerminator())
    {
        // Return true:
        return true;
    }

    // Otherwise, return false:
    return false;
}

vector<string> Trie::complete(string partialWord)
{
    // Create a string vector to return:
    vector<string> stringVector;

    // Find the node for the given partial word, if any:
    TrieNode *partialNode = findHelper(partialWord);

    // If a node was found:
    if (partialNode != nullptr)
    {
        // Then start searching for complete words:
        partialNode->completeHelper(partialWord, stringVector);
    }

    // Return the string vector:
    return stringVector;
}

int Trie::completeCount(string partialWord)
{
    // Use the complete function to find all instances of the given word:
    vector<string> stringVector = complete(partialWord);

    // Count the number of words in the string vector:
    int count = stringVector.size();

    // Return the count:
    return count;
}

/* Overrides */

Trie &Trie::operator=(const Trie &other)
{
    // Clean this trie, deleting all the nodes recursively:
    delete root;

    // Create a deep copy of the original root node, recursively adding deep copies of children:
    root = root->copyHelper(other.root);

    // Copy the node and word counts:
    wordCount = other.wordCount;
    nodeCount = other.nodeCount;
}