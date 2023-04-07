# Research Paper
Name: Shujun Chen   
Semester: 23 Fall   
Topic: Trie (prefix tree) data structure     
Link The Repository: https://github.com/Spring23-CS5008-BOS-Lionelle/research-project-Juneechen.git 

## Introduction
This report provides an overview of the Trie data structure and its practical applications. [Trie], also known as prefix tree or digital tree, is a data structure used for storing and retrieving sequences of symbols from within a set. The sequence of symbols could be binary bits or ASCII characters. The concept of a Trie was first described abstractly by Axel Thue in 1912, and later independently described by Edward Fredkin in 1960. Although it was originally named after the word 'retrieval', it is now most commonly pronounced as /ˈtraɪ/ (try). Tries are commonly used to solve problems that involve searching, spell checking, autocompletion, and other text processing operations. This report will discuss the implementation details, time and space complexity, and some use cases of Tries. Additionaly, the advantages and limitations of Trie will be discussed in comparison with other data structures.

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
To evaluate the performance of the Trie implementation in practice, a script was developed to measure the execution time of each function, with the help from this guide to [measure_execution_time].

This script [timer.cpp] measures the time taken for different Trie operations with Trie sizes ranging from $n = 1$ to $n = 10000$

It first sets up a `vector` of $10000$ random 10-letter `string`, and then loops over `n` from $1$ to $10000$ with a step of $10$. In each iteration, it inserts the first $n-1$ strings from the `vector` into a new `Trie` object. Then, it measures the time taken to insert the $n^{th}$ string, and to perform perform one operation for each of the main functionalities.

The duration of each operations is measured in `nanosecond` using the `chrono` library, as Trie operations are really fast and even `microsecond` did not provide enough precision for some durations. The results are then written to a CSV file named `"runtime.csv"`, and a graph is generated to visualize the Trie's performance:  

![runtime_graph]

As shown in the above graph, the runtime of `insert`, `search`, and `startWith` operations does not growth as the Trie size increases, displaying a constant runtime consistent with their Big O runtime of $O(1)$. The `getAllWithPrefix` operation exhibits a linear growth with the Trie size, as expected from its linear Big O runtime of $O(K+L)$ where $K$ is the number of strings with that prefix.

## Application
- What is the algorithm/datastructure used for?
- Provide specific examples
- Why is it useful / used in that field area?
- Make sure to provide sources for your information. 

Trie is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. Triesa allows for constant time lookup and insertion, but every single character has to be traversed through. That being said, in some cases, BSTs or Hash Table may perform better in those operation, as the entire string can be accessed altogether once found.  

However, the greatest advantage of Tries is that they are capable of efficiently perform various string operations not supported by its alternatives. For instance, tries allows for look up by prefix, which cannot be easily achieved with hash tables, in which words are stored as a whole intead of character by character.

The most common application of Tries is autocomplete. Additionaly, a priority value can be stored with each string to allow for suggesting the most often used strings before other options. The Google search bar gives a list of recommendation as we type, and that can be theoretically done with the following steps:  
- store billions of strings in a Trie
- associate a priority value that gets updated oftern to each string
- call a method that return strings with a given prefix as we type
- display the 10 strings with top priority, which can be optimized by using a priority queue



## Implementation
- What language did you use?
- What libraries did you use?
- What were the challenges you faced?
- Provide key points of the algorithm/datastructure implementation, discuss the code.
- If you found code in another language, and then implemented in your own language that is fine - but make sure to document that.

### Language
My implementation of Trie is written in C++, as my initial implememtation was relatively simple and I wanted to take up the challenge of trying out a language I'm not familiar with. As my Trie implementation is used to store Strings, the `<string>` library is used. The initial challenge I faced was learning the C++ syntax. It's quite different from C in syntax and the support of class and objects. Below is an example of the `constructor` for `TrieNode` struct:
```
    TrieNode() : isKey(false), children(10) {} // constructor
```
The above code shows a special syntax called an initialization list, which is used in the constructor of a class or struct to initialize member variables before the body of the constructor is executed.   


### Key Implementation Decisions
 

The underlaying structure for mapping a node represeing one char to its collection of children is one of the most important decisions in implemention a Trie, as it greatly affects the operation performance and space required in handling large data set with Trie.   

One way of implementing the children collection is with Arrays, which are fixed-sized in C++. For a Trie to support all ASCII charaters, the array should be declared to have size 128. For a Trie to support only lower-case English alphabets, the array should be declared to have size 26. Below is an example an array-based `TrieNode` from the [Introduction_to_Trie] from GeeksForGeeks:
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

I explored other options for representing children nodes

I studied and learned from the GeeksForGeeks, adn for the purpose of exercise, I explored other options for representing children nodes. I tried implementing my TrieNode differenly using a the C++ built-in hashmap


### Main Functionalities Code Walk-through

### Extra Functionality
As I finished implementing the basic operations that should be supported by a Trie, I continued to explore extra functionalities.

## Summary
- Provide a summary of your findings
- What did you learn?

## Reference
- https://brilliant.org/wiki/tries/
- https://algs4.cs.princeton.edu/code/javadoc/edu/princeton/cs/algs4/TST.html
- https://www.toptal.com/java/the-trie-a-neglected-data-structure
- https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/

<!-- auto references -->
[Trie]: https://en.wikipedia.org/wiki/Trie
[Introduction_to_Trie]: https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/
[measure_execution_time]: https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
[timer.cpp]: ./timer.cpp
[runtime_graph]: ./trie_runtime_grapg.png