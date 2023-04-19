CC = g++
CFLAGS = -Wall 

all: testTrie.out timer.out

testTrie.out: testTrie.cpp Trie.cpp
	$(CC) $(CFLAGS) -o testTrie.out testTrie.cpp Trie.cpp

timer.out: timer.cpp Trie.cpp
	$(CC) $(CFLAGS) -o timer.out timer.cpp Trie.cpp

clean:
	rm -f testTrie.out timer.out