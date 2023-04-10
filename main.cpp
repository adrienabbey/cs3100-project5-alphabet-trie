// Adrien Abbey, CS-3100, Mar. 30, 2023
// Project #5: Autocomplete with an Alphabet Trie
// VS Code, Ubuntu 22.04, g++/gdb

/*
 * Notes:
 *  - Since we are provided dictionaries to work with, I'm going to assume
 *    that we're ONLY working with 26 lowercase letters plus a terminating
 *    'character'.  This means not only no capital letters, but also no
 *    punctuation or other characters.
 */

#include <iostream>
#include <vector>
#include <fstream> // Enables file reading
#include <string>
#include <iomanip> // Enable empty input
#include "Trie.h"

using namespace std;

/* Method Declarations */

vector<string> loadDictionary(string fileName);
bool inputSequence(Trie *dictionaryTrie);

int main()
{
    // Char test:
    // char testChar = 'a';
    // int charInt = testChar - 'a' + 1;
    // cout << "Character " << testChar << "'s int value is: " << charInt << endl;

    // Create an empty trie:
    // Trie *testTrie = new Trie();

    // Insert test:
    // testTrie->insert("hello");

    // Create an empty trie:
    Trie *emptyTrie = new Trie();

    // Load the appropriate dictionary into a trie:
    vector<string> dictionary = loadDictionary("wordlist_linux.txt");

    // Create a new trie:
    Trie *alphaTrie = new Trie();

    // For every word in the dictionary:
    for (string word : dictionary)
    {
        // Insert the word into the trie:
        alphaTrie->insert(word);
    }

    // Test duplicate word insertion:
    cout << "Duplicate insertion returns: " << alphaTrie->insert("cat") << endl;

    // Test word and node counters:
    cout << "Word count: " << alphaTrie->count() << endl
         << "Node Count: " << alphaTrie->getSize() << endl;

    // Test the find function:
    cout << "Find cat returns: " << alphaTrie->find("cat") << endl
         << "Find ca returns: " << alphaTrie->find("ca") << endl
         << "Find foobar returns: " << alphaTrie->find("foobar") << endl;

    // Test the complete function:
    vector<string> findCatVector = alphaTrie->complete("cat");
    for (string s : findCatVector)
    {
        cout << s << ", ";
    }

    // Test the completeCount function:
    cout << endl
         << endl
         << "Number of words starting with cat: " << alphaTrie->completeCount("cat") << endl;

    // Test the copy constructor:
    Trie *copyConstructorTrie = new Trie(*alphaTrie);

    // Test the TrieNode deconstructor:
    delete alphaTrie;

    // Test the =operator overload:
    emptyTrie = copyConstructorTrie;

    // Test the find function on the now-full emptyTrie:
    cout << "Number of words starting with dog: " << emptyTrie->completeCount("dog") << endl
         << endl;

    // Loop the user input sequence:
    bool keepLooping = true;

    while (keepLooping)
    {
        keepLooping = inputSequence(emptyTrie);
    }

    return 0;
}

/// @brief Loads words from the given file, adding them to a string vector,
/// then returns that string vector.
/// @param fileName A string containing the file name to load words from.
/// @return Returns a string vector containing each word loaded from the
/// provided file.
vector<string> loadDictionary(string fileName)
{
    // Create a ifstream pointing to the dictionary:
    ifstream dictFile(fileName);

    // Create a string vector of words:
    vector<string> wordList;

    // If the file loaded correctly:
    if (dictFile.good())
    {
        // Create a string to hold a new word:
        string newWord;

        // While there are words to load from the dictionary:
        while (!dictFile.eof())
        {
            // Pipe the next word into the string:
            dictFile >> newWord;

            // Push the new word onto the string vector:
            wordList.push_back(newWord);
        }
    }
    // Otherwise, if the dictionary file failed to load:
    else
    {
        // Print an error message:
        cerr << "Failed to load the dictionary file!" << endl;
    }

    // Return the string vector:
    return wordList;
}

/// @brief Prompts for a word prefix, then grabs input from the user.  If an
/// input is given, search the current trie, displaying the number of results,
/// then prompting to display the results.
/// @param dictionaryTrie A Trie containing the dictionary to search through.
/// @return If true, an input was given.  If false, no input was given.
bool inputSequence(Trie *dictionaryTrie)
{
    // Prompt for a prefix:
    cout << "Please enter a word prefix (or press enter to exit):  ";

    // Allow empty input:
    // https://stackoverflow.com/a/17871395
    cin >> noskipws;

    // Grab input:
    string inputString;
    cin >> inputString;
    cin.clear();
    cin.ignore();

    // If the user gave an input:
    if (inputString.size() > 0)
    {
        // Display search results:
        cout << "There are " << dictionaryTrie->completeCount(inputString) << " completions for the prefix '" << inputString << "'.  Show completions? ";

        // Grab input:
        string boolInput;
        cin >> boolInput;
        cin.clear();
        cin.ignore();
        bool boolResult;

        // Lazily convert the input string to a boolean value:
        if (boolInput.compare("yes") == 0)
        {
            boolResult = true;
        }
        else
        {
            boolResult = false;
        }

        // If the user wants results:
        if (boolResult)
        {
            // Print out the completions:
            cout << "Completions" << endl
                 << "-----------" << endl;

            // Find all the words found:
            vector<string> searchResults = dictionaryTrie->complete(inputString);
            for (string s : searchResults)
            {
                // Print out the word:
                cout << s << endl;
            }
        }

        // Return true to loop again:
        return true;
    }
    // Otherwise the user gave no input:
    else
    {
        return false;
    }
}