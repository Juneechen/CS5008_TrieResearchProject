#include <iostream>
#include "Trie.h"

using namespace std;

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

    cout << words.size() << endl;

    for (string each : words) {
        cout << each << endl;
    } 

    return 0;
}