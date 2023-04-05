#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie() {
        root = new TrieNode();
        totalWords = 0;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            
        }
        
        if (!curr->isKey) {
            totalWords++;
            curr->isKey = true;
        }
        curr->freq++;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isKey;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

private:
    struct TrieNode {
        bool isKey;
        int freq;
        unordered_map<char, TrieNode*> children;

        TrieNode() : isKey(false), freq(0), children(10) {}
    };

    TrieNode* root;
    int totalWords;
};