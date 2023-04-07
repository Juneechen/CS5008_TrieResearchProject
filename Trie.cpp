#include <iostream>
#include "Trie.h"

using namespace std;

Trie::Trie() {
    root = new TrieNode();
    totalWords = 0;
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(string word) {
    TrieNode* curr = root;
    for (char c : word) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        
    }

    if (!curr->isWord) {
        totalWords++;
        curr->isWord = true;
    }
    curr->freq++;
}

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

void Trie::print() {
    cout << "\nTotal words: " << this->totalWords << endl;
    printNode(this->root, "");
    cout << "\n";
}

vector<string> Trie::getAllWithPrefix(string prefix) {
    vector<string> res;
    TrieNode* curr = root;
    for (char c : prefix) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {
            return res;
        }
        curr = curr->children[c];
    }
    getAllWithPrefixHelper(res, curr, prefix);
    return res;
}

Trie::TrieNode::TrieNode() : isWord(false), freq(0), children(10) {}

Trie::TrieNode::~TrieNode() {
    for (auto& each : this->children) {
        delete each.second;
    }
}

void Trie::printNode(TrieNode * curr, string prefix) {
    if (curr->isWord) {
        cout << prefix << "\tfrequency: " << curr->freq << endl;
    }
    for (auto each : curr->children) {
        printNode(each.second, prefix + each.first);
    }
}

void Trie::getAllWithPrefixHelper(vector<string>& res, TrieNode* curr, string prefix) {
    if (curr->isWord) {
        res.push_back(prefix);
    }
    for (auto each : curr->children) {
        getAllWithPrefixHelper(res, each.second, prefix + each.first);
    }
}