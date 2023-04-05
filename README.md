# Research Paper
Name: Shujun Chen   
Semester: 23 Fall   
Topic: Trie (prefix tree) data structure     
Link The Repository: https://github.com/Spring23-CS5008-BOS-Lionelle/research-project-Juneechen.git 

## Introduction
This report looks at the fundamental concepts of the Trie data structure and its application. [Trie], also known as prefix tree or digital tree, is a data structure used for storing and retrieving sequence of symbols from within a set. The sequence of symbols could be binary bits or ASCII characters. The idea of a trie was first abstractly described by Axel Thue in 1912, and later independently described by Edward Fredkin in 1960. Its name came from the word 'Retrieval' but it is now most often pronounced as /ˈtraɪ/. Tries are commonly used to solve problems involve searching, spell checking, autocompletion, and other text processing operations. The rest of this report on Trie will discuss its implementation details, time and space complexity, and some use cases. Additionaly, the advantages and limitations of Trie will be discussed in comparison with other data structures.

## Analysis of Algorithm/Datastructure
Make sure to include the following:
- Time Complexity
- Space Complexity
- General analysis of the algorithm/datastructure

## Empirical Analysis
- What is the empirical analysis?
- Provide specific examples / data.


## Application
- What is the algorithm/datastructure used for?
- Provide specific examples
- Why is it useful / used in that field area?
- Make sure to provide sources for your information.


## Implementation
- What language did you use?
- What libraries did you use?
- What were the challenges you faced?
- Provide key points of the algorithm/datastructure implementation, discuss the code.
- If you found code in another language, and then implemented in your own language that is fine - but make sure to document that.

### Language
My implementation of Trie is written in C++, as my initial implememtation was relatively simple and I wanted to take up the challenge of trying out a language I'm not familiar with. As my Trie implementation is used to store Strings, the `<string>` librarie is used. The initial challenge I faced was learning the C++ syntax. It's quite different from C in syntax and the support of class and objects. Below is a snippet of the `TrieNode` struct declared in my implementation:
```
struct TrieNode {
        bool isKey;
        unordered_map<char, TrieNode*> children;

        TrieNode() : isKey(false), children(10) {} // constructor
    };
```
The `constructor` marked in the above code shows a special syntax called an initialization list, which is used in the constructor of a class or struct to initialize member variables before the body of the constructor is executed.   


### Key Implementation Decisions
A Trie is a type of k-nary tree where each character in a word stored in the Trie can be represented by a node with a collection of children represent the next character in that word. The structure for representing the collection of children is one of the most important decisions in implemention a Trie, as it greatly affects the operation performance and space required in handling large data set with Trie.   

One way of implementing the children collection is with Arrays, which are fixed-sized in C++. For a Trie to support all ASCII charaters, the array should be declared to have size 128. For a Trie to support only English alphabetic character, the array should be declared to have size 26. Below is an example an array-based `TrieNode` from the [Introduction_to_Trie] from GeeksForGeeks:
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
One disadvantage of using a fixed size array in a Trie to represent children is that it can waste memory when the Trie is sparse, and take up too much memory when a large set of vocabularies is stored, as every single charater/node will have a pre-allocated array to accommodate the maximum number of possible children. One advantage of using arrays is that it will be easy to retrieve all stored word in sorted alphabetical order.

I studied and learned from the GeeksForGeeks, but for the purpose of exercise, I explored other options for representing children nodes, and implemented my TrieNode differenly using a the C++ built-in hashmap.


### Main Functionalities Code Walk-through

### Extra Functionality
As I finished implementing the basic operations that should be supported by a Trie, I continued to explore extra functionalities.

## Summary
- Provide a summary of your findings
- What did you learn?

## Reference
- 


<!-- auto references -->
[Trie]: https://en.wikipedia.org/wiki/Trie
[Introduction_to_Trie]: https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/