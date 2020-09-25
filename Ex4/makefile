



frequency: trie.o main.o
	gcc -Wall -o frequency main.o trie.o

main.o: main.c trie.h
	gcc -Wall -c main.c

trie.o: trie.c trie.h
	gcc -Wall -c trie.c	


.PHONY: clean all 

clean:
	rm -f *.o frequency 

all: frequency 
