#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    TrieNode() : isKey(false), children(10) {}

    void insert(string word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isKey = true;
    }

    bool search(string word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isKey;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = this;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

private:
    bool isKey;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word);
    }
    
    bool startsWith(string prefix) {
        return root->startsWith(prefix);
    }

private:
    TrieNode* root;
};