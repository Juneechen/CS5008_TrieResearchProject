#include <iostream>
#include "Trie.h"

using namespace std;

Trie::Trie() {
    root = new TrieNode();
    totalWords = 0;
}

/** 
 * destructor, used to free allocated memory, invoked by delete keyword?
 */
Trie::~Trie() {
    delete root;
}

/**
 * insert a word into the Trie, by having each char represented by a node
 */
void Trie::insert(string word) {
    TrieNode* curr = root;
    for (char c : word) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) { // if not found, find() returns an iterator pointing to the end of the map, which is represented by map.end()
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        
    }

    if (!curr->isWord) {    // if this char is not marked as the end of a word
        totalWords++; 
        curr->isWord = true;    // mark as the end of a word
    }
    curr->freq++;   // frequency was 0 when this char node first created but not marked as the end of a word
}

/**
 * answer whether the given word is present in this Trie.
 */
bool Trie::search(string word) {
    TrieNode* curr = root;
    for (char c : word) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children[c];
    }
    return curr->isWord;
}

/**
 * answer whether the Trie contains any word that starts with the given prefix. 
*/
bool Trie::startsWith(string prefix) {
    TrieNode* curr = root;
    for (char c : prefix) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children[c];
    }
    return true;
}

/**
 * print all words in this Trie; order of words is not preserved since my Trie is hash-map based instead of array-based.
 */
void Trie::print() {
    cout << "\nTotal words: " << this->totalWords << endl;
    printNode(this->root, "");
    cout << "\n";
}

/**
 * get all words with the given prefix.
 */
vector<string> Trie::getAllWithPrefix(string prefix) {
    vector<string> res;
    TrieNode* curr = root;
    for (char c : prefix) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {
            return res;     // empty if the prefix itself is not even in the Trie
        }
        curr = curr->children[c];
    }
    // got to the end of the original prefix by now
    getAllWithPrefixHelper(res, curr, prefix);
    return res;
}

/**
 * construct a TrieNode representing a char, which a hashmap of 10 buckets (grows when needed) to represent its children.
 */
Trie::TrieNode::TrieNode() : isWord(false), freq(0), children(10) {}

/**
 * destructor to free a TrieNode along with all its children; done with recursion since each children contains another TrieNode
 */
Trie::TrieNode::~TrieNode() {
    for (auto& each : this->children) {     // for each pair in the children hashmap
        delete each.second;     // .second represents the value in a hashmap pair, which is the children of one of the children of the curr node.
    }
}

/**
 * a recursive print helper; recursively print a node with all its children.
 */
void Trie::printNode(TrieNode * curr, string prefix) {
    if (curr->isWord) {
        cout << prefix << "\tfrequency: " << curr->freq << endl;
    }
    for (auto each : curr->children) {
        printNode(each.second, prefix + each.first); // .first represent the key in a hashmap pair, which is the char represented by this TrieNode 
    }
}

/**
 * a recursive helper to get all words with a given prefix.
 */
void Trie::getAllWithPrefixHelper(vector<string>& res, TrieNode* curr, string prefix) {
    if (curr->isWord) {
        res.push_back(prefix); 
    }
    for (auto each : curr->children) { 
        getAllWithPrefixHelper(res, each.second, prefix + each.first); 
    }
}