#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie() {
        root = new TrieNode();
        totalWords = 0;
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
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
    
    bool startsWith(string prefix) {
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

    void print() {
        cout << "\nTotal words: " << this->totalWords << endl;
        printNode(this->root, "");
        cout << "\n";
    }

    vector<string> getAllWithPrefix(string prefix) {
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

private:
    struct TrieNode {
        bool isWord;
        int freq;
        unordered_map<char, TrieNode*> children;

        TrieNode() : isWord(false), freq(0), children(10) {}

        ~TrieNode() {
            for (auto& each : this->children) {
                delete each.second;
            }
        }
    };

    TrieNode* root;
    int totalWords;

    void printNode(TrieNode * curr, string prefix) {
        if (curr->isWord) {
            cout << prefix << "\tfrequency: " << curr->freq << endl;
        }
        for (auto each : curr->children) {
            printNode(each.second, prefix + each.first);
        }
    }

    void getAllWithPrefixHelper(vector<string>& res, TrieNode* curr, string prefix) {
        if (curr->isWord) {
            res.push_back(prefix);
        }
        for (auto each : curr->children) {
            getAllWithPrefixHelper(res, each.second, prefix + each.first);
        }
    }
};

int main() {
    Trie myTrie;

    myTrie.insert("apply");
    myTrie.insert("cat");
    myTrie.insert("apple");
    myTrie.insert("apply");
    myTrie.insert("catalog");
    myTrie.insert("banana");
    myTrie.insert("keep");
    myTrie.insert("bad");

    myTrie.print();

    vector<string> words = myTrie.getAllWithPrefix("a");

    cout << words.size();

    for (string each : words) {
        cout << each << endl;
    } 

    return 0;
}