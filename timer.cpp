#include <fstream>
#include <chrono>
#include "Trie.h"

using namespace std;

int main() {
    ofstream outputFile("runtime.csv");
    outputFile << "n,insertDuration,searchDuration,startsWithDuration,getAllWithPrefixDuration\n";

    vector<string> words; // makes up a collection of strings to be put into the Trie
    words.reserve(10000); // reserve enough space
    // generates 10000 random strings
    for (int i = 0; i < 10000; i++) {
        string word;
        // one random string of length 10 
        for (int j = 0; j < 10; j++) {
            word += 'a' + rand() % 26;
        }
        words.push_back(word); // add to `words`
    }

    // make Tries of size from 1 to 10000, with each Trie of size n, time each operation
    for (int n = 1; n <= 10000; n+=10) {
        Trie trie;
        // put n-1 strings into the Trie:
        for (int i = 0; i < n-1; i++) {
            trie.insert(words[i]);
        }
        
        // time inserting the nth string while n-1 string alreay in the trie
        auto start = chrono::high_resolution_clock::now();
        trie.insert(words[n-1]);
        auto end = chrono::high_resolution_clock::now();
        auto insertDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        // time searching a word
        start = chrono::high_resolution_clock::now();
        trie.search(words[n-1]);
        end = chrono::high_resolution_clock::now();
        auto searchDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        // time startsWith() 
        start = chrono::high_resolution_clock::now();
        trie.startsWith(words[n-1].substr(0, 2));
        end = chrono::high_resolution_clock::now();
        auto startsWithDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        // time startsWith() 
        start = chrono::high_resolution_clock::now();
        trie.getAllWithPrefix(words[n-1].substr(0, 2));
        end = chrono::high_resolution_clock::now();
        auto getAllWithPrefixDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        
        // append the above durations into the output file
        outputFile << n << "," << insertDuration << "," << searchDuration << "," << startsWithDuration << "," << getAllWithPrefixDuration << "\n";
    }

    outputFile.close();

    return 0;
}
