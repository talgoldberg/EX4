#ifndef EX4_TRIE_H
#define EX4_TRIE_H
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define NUM_LETTES 26
#define NUM_MAX 1000

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
    char letter;
    boolean isEndOfWord;
    long unsigned int count;
    struct node* children[NUM_LETTES];
}node;


char* notChar (char a[],int i);
void insert(node *root,  char *key,int length);
node* setNull();
int makeTrie (char b[],node* root,int lengthB);
void printRoot (node* root,int maxWord);
void printNode (node* currentNode, char* str, int length);
void printRootReverse (node* root,int maxWord);
void printNodeReverse (node* currentNode, char* str, int length);
void freeRoot (node* root);

#endif //EX4_TRIE_H