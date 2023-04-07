#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Trie {
public:
    Trie();
    ~Trie();

    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
    void print();
    vector<string> getAllWithPrefix(string prefix);

private:
    struct TrieNode {
        bool isWord;
        int freq;
        unordered_map<char, TrieNode*> children;

        TrieNode();
        ~TrieNode();
    };

    TrieNode* root;
    int totalWords;

    void printNode(TrieNode* curr, string prefix);
    void getAllWithPrefixHelper(vector<string>& res, TrieNode* curr, string prefix);
};

#endif