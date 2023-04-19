# Research Paper
Name: Shujun Chen   
Semester: 23 Fall   
Topic: Trie (prefix tree) data structure     
Link The Repository: https://github.com/Spring23-CS5008-BOS-Lionelle/research-project-Juneechen.git 

## Introduction
This report provides an overview of the Trie data structure and its practical applications. [Trie], also known as prefix tree or digital tree, is a data structure used for storing and retrieving sequences of symbols from within a set. The sequence of symbols could be binary bits or ASCII characters.     

The concept of a Trie was first described abstractly by Axel Thue in 1912, and later independently described by Edward Fredkin in 1960. Although it was originally named after the word 'retrieval', it is now most commonly pronounced as /ˈtraɪ/ (try).     

Tries are commonly used to solve problems that involve searching, spell checking, autocompletion, and other text processing operations. This report will discuss the implementation details, time and space complexity, and some use cases of Tries. Additionaly, the advantages and limitations of Trie will be discussed in comparison with other data structures. Below graph shows what a Trie looks like:

![trie.png]

## Analysis of Algorithm/Datastructure
A Trie is a type of k-nary tree with one root node,which has a collection of children nodes, each representing a character with its own children. Each node in the Trie has a boolean value indicating whether it represents the end of a word. The time and space complexity of the Trie data structure will be discussed in this section, with the results presented in the following chart representing their Big O values: 

| Operation | Time |
| :-- | :-- | 
| insert | $O(1)$ |
| contains / search | $O(1)$ |
| getAllWithPrefix | $O(K+P)$ |
| print | $O(N)$ |
| Space | $O(N*R)$ |

The above time complexity analysis is for an array-based Trie implementation.   

The operations `insert` and `contains` have constant runtime because, starting from the root, we always know where the next character goes, and the number of nodes to traverse is always `L`, the length of the string. Since `L` is not growing with the number of strings in the Trie, these operations can be said to have $O(1)$ constant runtime.  

The `getAllWithPrefix` operation has a time complexity of $O(K+P)$, where `K` is the number of strings with the prefix and P is the length of the prefix. This is because to get from the root to the end of the prefix, `P` nodes will be traversed. After that, each of the `K`children will be visited, giving a total of $O(K+P)$ runtime, which is linear.   

The `print` operation has a time complexity of $O(N)$, where `N` is the number of nodes in the Trie. This is because for all the strings stored in the Trie be printed out, every single node will be visited exactly once.

When it comes to space complexity, an array-based Trie requires $O(N*R)$ space, where `N`is the number of nodes presented, and `R` is the number of different `char` supported by the implementation. This is because each of the `N` nodes will have an array of size `R` reserved for all possible children.

Overall, Trie operations are efficient, but the structure can take up a lot of space. The Trie data structure displays a clear trade-off between time and space.


## Empirical Analysis
To evaluate the performance of the Trie implementation in practice, a script was developed to measure the execution time of each function, with the help from this guide to [measure execution time].

This script [timer.cpp] measures the time taken for different Trie operations with Trie sizes ranging from $n = 1$ to $n = 10000$. An executable `timer.out` can be created with terminal command `make`.

It first sets up a `vector` of $10000$ random 10-letter `string`, and then loops over `n` from $1$ to $10000$ with a step of $10$. In each iteration, it inserts the first $n-1$ strings from the `vector` into a new `Trie` object. Then, it measures the time taken to insert the $n^{th}$ string, and to perform perform one operation for each of the main functionalities.

The duration of each operations is measured in `nanosecond` using the `chrono` library, as Trie operations are really fast and even `microsecond` did not provide enough precision for some durations. The results are then written to a CSV file named `"runtime.csv"`, and a graph is generated to visualize the Trie's performance:  

![runtime_graph]

As shown in the above graph, the runtime of `insert`, `search`, and `startWith` operations does not growth as the Trie size increases, displaying a constant runtime consistent with their Big O runtime of $O(1)$. The `getAllWithPrefix` operation exhibits a linear growth with the Trie size, as expected from its linear Big O runtime of $O(K+L)$ where $K$ is the number of strings with that prefix.

## Application
Trie is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. Triesa allows for constant time lookup and insertion, but every single character has to be traversed through. That being said, in some cases, BSTs or Hash Table may perform better in those operation, as the entire string can be accessed altogether once found.  

However, the greatest advantage of Tries is that they are capable of efficiently perform various string operations not supported by its alternatives. For instance, tries allows for look up by prefix, which cannot be easily achieved with hash tables, in which words are stored as a whole intead of character by character.

### Autocomplete
The most common application of Tries is [autocomplete]. Additionaly, a priority value can be stored with each string to allow for suggesting the most often used strings before other options. The Google search bar gives a list of recommendation as we type, and that can be theoretically done with the following steps:  
- store billions of strings in a Trie
- associate a priority value that gets updated oftern to each string
- call a method that return strings with a given prefix as we type
- display the 10 strings with top priority, which can be optimized by using a priority queue

### IP Routing
Trie can also be used for efficient [IP Routing], which stands for Internet Protocol Routing, and it involves the process of determining the path to forward packets of data from one netword to another. Routers need to be able to perform IP address lookups quickly to efficiently determine the appropriate network interface through which to forward packets.    

In [this paper] titled "Fast Table-Update Scheme and Implementation of a Trie-based Scheme for Fast IP Lookup", the authors describe a routing table represented as a Trie, where each node represents a partial IP address prefix. By traversing down the Trie with each bit of the IP address, the longest matching prefix can be found, which represents the network to which the IP address belongs. The paper explains how Tries enable fast address lookups and reduced number of memory accesses required for each lookup. Overall, Tries enables fast and accurate IP address lookups, which is essential for efficient network routing.

## Implementation
Note: command `make` is setup to make executable `testTrie.out` and `timer.out`.     

[Trie.h]:       struct `Trie` and `TrieNode` declaration.    
[Trie.cpp]:     provides actual implementation for all methods from the `Trie` and `TrieNode` struct.    
[testTrie.cpp]: a simple test use of my Trie implementation.    
[makefile]:     capable of making executable `testTrie.out` and `timer.out`.    

### Language
I chose to use C++ for my Trie implementation, as my initial implementation was relatively simple and I wanted to take on this challenge of using a language I am not familiar with. Since my Trie implementation is used to store Strings, the `<string>` library is used. The initial challenge I faced was learning C++, which differs from C in syntax and its use of classes and objects. Here is an example of the constructor for the TrieNode struct:
```
    TrieNode() : isKey(false), children(10) {} // constructor
```
The above code shows a special syntax called an initialization list, which is used in the constructor of a class or struct to initialize member variables before the body of the constructor is executed.   


### Key Implementation Decisions
The underlaying structure for mapping a node representing one char to its collection of children is one of the most important decisions in implemention a Trie, as it greatly affects the operation performance and space required in handling large data set with Trie.   

### array-based children
One way of implementing the children collection is with Arrays, which are fixed-sized in C++. For a Trie to support all ASCII charaters, the array should be declared to have size 128. For a Trie to support only lower-case English alphabets, the array should be declared to have size 26. Below is an example an array-based `TrieNode` from the [Introduction to Trie] from GeeksForGeeks:
```
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
 
    // This will keep track of number of strings that are
    // stored in the Trie from root node to any Trie node.
    int wordCount = 0;
};
```
The value of the character itself is omited from the `TrieNode` as it is represented by the char's position in the array. Given a `TrieNode* p`, the node representing any specific `char c` can be accessed simply with:
```
    p->children[c]
```
One disadvantage of using a fixed size array in a Trie to represent children is that it can waste memory when the Trie is sparse. When a Trie is designed to 26 letters (a-z), but the actual words inserted into the Trie use only a subset of these letters, then most of the slots in the array will be unused, resulting in wasted memory. This also results in increased memory usage when a large set of vocabularies is stored, as every single node will have a pre-allocated array to accommodate the maximum number of possible children. One advantage of using arrays is that it will be easy to retrieve all stored word in sorted alphabetical order.  

### hashmap-based children
I studied and learned from the [Introduction to Trie] on GeeksForGeeks, and for the purpose of exercise, I explored other options for representing children nodes. I eventually implemented my TrieNode differenly using the C++ hashmap from the `<unordered_map>` library as such: 
```
struct TrieNode {
        bool isWord;
        int freq;
        unordered_map<char, TrieNode*> children;

        TrieNode() : isWord(false), freq(0), children(10) {}
        ~TrieNode();
};
```
Hash map is a more dynamic structure comparing to array. It allows for more efficient memory usage and dynamic adjustment for the number of children as needed. The above map is initialized with 10 buckets, however that is not fixed, it will get resized once it reaches a certain load factor as determined by the `<unordered_map>` library. A hashmap-based Trie takes up less space, as it will not have un-used links pointing to `null` for non-existing children. However, it can be slower in performance due to the overhead from setting up the hashmap and computing hash value. Moreover, it does not maintain an alphebetical order for the nodes. 

### Main Functionalities Code Walk-through
The `insert(string word)` and `search(string word)` operations are very similar, both involve the process of traversing down the Trie through each character in the word, by having a `curr` pointer starting from the Trie root and moving through nodes representing the next character.    
When a character is not present along the path, `search` would simply return false, while `insert` would make a new node representing that char:
```
void Trie::insert(string word) {
    TrieNode* curr = root;
    for (char c : word) {
        c = tolower(c);
        if (curr->children.find(c) == curr->children.end()) {   // not found
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];   // found, move curr pointer to that char
    }
    ...
}
```    
Note that if `c` is not found, `map.find(c)` returns an iterator pointing to the end of the map, which is represented by `map.end()`; `children[c]` is used to represent the character `c`, as each char is a value in its previous char's children map.   

When all characters in the word has been found, `search` would return true if the last char is marked as the end of a word, false otherwise, while `insert` would simply mark that char as the end of a word and increment its frequency and the total word count if the word was not in the Trie:
```
void Trie::insert(string word) {
    TrieNode* curr = root;

    ...

    if (!curr->isWord) {    // if this char is not marked as the end of a word
        totalWords++; 
        curr->isWord = true;    // mark as the end of a word
    }
    curr->freq++;
}
```
Note that each char node's frequency was 0 when it's first created but not marked as the end of a word.    

The `getAllWithPrefix` operation recursively finds all words with a given prefix. It does so by first traverse to the ending char of the prefix, then it calls a recursive helper to find all words from children of that ending char:
```
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
```   

The `getAllWithPrefixHelper` traverses through all children till reaching the leaf node, then adds to the result vector whenever it encounters a node mark as the end of a word:
```
getAllWithPrefixHelper(vector<string>& res, TrieNode* curr, string prefix) {
    if (curr->isWord) {     // found a word
        res.push_back(prefix); 
    }
    for (auto each : curr->children) { 
        getAllWithPrefixHelper(res, each.second, prefix + each.first); 
    }
}
```
Note that `.first` represents the key in a hashmap pair, and `.second` represents the value in a hashmap pair. In the above code, `.first` gives the char itself, which is then appended to the prefix, then passed down to the recursive function called on `.second`, which is one of the children node (representing a next char) of the current node.    

## Summary
Tries are a powerful data structure for storing and processing strings, with applications in various fields, such as text editors, IP routers, search engines, and more. Trie's operations are faster than some of its alternatives such as BST or Hash Table in theory, however, the ability to process strings character by charter is the top reason why Tries are useful.    

Trie's performance and memory usage dependent on the concrete implementation used for its char-to-children mapping. There are various options, each comes with its own advantages and limitations, and there is likely no best choice. Some options are more flexible, however, they may come with their own overhead. The choice of data structure to represent children in a Trie depends on the specific requirements and constraints of the application. Factors such as whether the Trie will be relatetively stable or dynamic, and whether the order of keys is important, should all be taken into account when making the implementation decision. I've learned that it is always important to carefully consider the trade-offs between memory usage, performance, and flexibility when chooseing the concrete implementation for an abstract representation. 

## Reference
- https://brilliant.org/wiki/tries/
- https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/TST.html
- https://www.toptal.com/java/the-trie-a-neglected-data-structure
- https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/
- https://www.lewuathe.com/longest-prefix-match-with-trie-tree.html
- https://www.routerfreak.com/what-is-ip-routing-how-does-it-work/

<!-- auto references -->
[Trie]: https://en.wikipedia.org/wiki/Trie
[Introduction to Trie]: https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/
[measure execution time]: https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
[this paper]: https://web.njit.edu/~rojasces/publications/08iberchipiplookup.pdf
[autocomplete]: https://www.geeksforgeeks.org/auto-complete-feature-using-trie/
[IP Routing]: https://en.wikipedia.org/wiki/IP_routing
[Trie.h]: ./Trie.h
[Trie.cpp]: ./Trie.cpp
[testTrie.cpp]: ./testTrie.cpp
[makefile]: ./makefile
[timer.cpp]: ./timer.cpp
[runtime_graph]: ./trie_runtime_graph.png
[Trie.png]: ./Trie.png