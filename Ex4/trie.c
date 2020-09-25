
#include <stdio.h>
#include "trie.h"
/*
 * Reads the input and puts every word in the tree
 */
int makeTrie (char b[],node* root,int lengthB)
{
    int maxWord=0;
    int length=0;
    char* help=NULL;
    help= (char*)malloc(sizeof(char)*2*lengthB);
    if(help==NULL)
    {
        printf("error\n");
        exit(1);
    }
    int i=0;
    for (int start=0; start < lengthB; start++)
    {
        if (b[start] != ' ') {
            help[i++] = b[start];

        } else {
            help[i] = '\0';
            char *h = notChar(help,i);
            for (int j = 0; h[j] != '\0'; j++)
            {
            length++;
            }
            if (length>maxWord) maxWord=length;
            insert(root, h,length);
            length=0;
            i = 0;
            free(h);

        }
        if (start == lengthB - 1)
        {
            help[i] = '\0';
            char *h = notChar(help,i);
            for (int j=0; h[j]!='\0' ;j++)
            {
                length++;
            }
            if (length>maxWord) maxWord=length;
            insert(root, h,length);
            free(h);
        }
    }

    free(help);
    return maxWord;
}

/*
 * this function check if we have chars that they no in a"b.
 * if we have the function remove them.
 * if we have a big char the function change it to small char.
 */
char* notChar (char a[],int i)
{

    char* help=NULL;
    int j=0;
    help= (char*)malloc(sizeof(char)*(i+1));
    memset(help,0, sizeof(char)*(i+1));
    if(help==NULL)
    {
        printf("error\n");
        exit(1);
    }
    for (int i = 0; a[i] !='\0' ; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {

            help[j++] = a[i] - 'A' + 'a';
        }
        if (a[i] >= 'a' && a[i] <= 'z')
        {

            help[j++] = a[i];
        }
    }
    return help;
}

/*
 * Returns first node-head
 * set null's
 */
node* setNull()
{
    node* head = NULL;

    head =(node*)malloc(sizeof(node));

    if (head!=NULL)
    {
        head->isEndOfWord = FALSE;
        head->count=0;

        for (int i = 0; i < NUM_LETTES; i++)
            head->children[i] = NULL;
    }

    return head;
}

/*If not present, inserts
 * If the key is prefix of trie node, just marks leaf node
 * update the counter if the word exist
 */
void insert(node* root,char *key,int length)
{
  //  node*test=setNull();
    int index;
    for (int i = 0; i <length; i++)
    {
        index = ((int)key[i] - (int)'a');
        if (!root->children[index])
        {

            root->children[index] =setNull();
            root->children[index]->letter=key[i];
        }
        root = root->children[index];
    }

    // mark the last node true (end word)
    root->isEndOfWord = TRUE;
    root->count++;

}

void printRoot (node* root,int maxWord)
{
    char* str =(char*)malloc(sizeof(char)*(maxWord+1));
    for (int i = 0; i < NUM_LETTES; i++)
    {
        if (root->children[i] != NULL)
        {
            printNode(root->children[i], str, 0);

        }
    }
    free(str);

}

void printNode (node* currentNode, char* str, int length)
{

    str[length] = currentNode->letter;
    str[length+1] = '\0';

    if(currentNode->isEndOfWord)
    {
        printf("%s", str);
        printf("\t%ld\n", currentNode->count);
    }
    for( int i = 0; i < NUM_LETTES; i++)
    {
        if (currentNode->children[i] != NULL)
        {
            printNode(currentNode->children[i], str, length+1);
        }

    }
}


void printRootReverse (node* root,int maxWord)
{
    char* str =(char*)malloc(sizeof(char)*(maxWord+1));

    for (int i = NUM_LETTES-1; i >=0; i--)
    {
        if (root->children[i] != NULL)
        {
            printNodeReverse(root->children[i], str, 0);
        }
    }

    free(str);

}

void printNodeReverse (node* currentNode, char* str, int length)
{
    str[length] = currentNode->letter;
    str[length + 1] = '\0';

    for (int i = NUM_LETTES-1; i >= 0; i--)
    {
        if (currentNode->children[i] != NULL)
        {
            printNodeReverse(currentNode->children[i], str, length + 1);
        }

    }
    if (currentNode->isEndOfWord)
    {
        str[length+1] = '\0';
        printf("%s", str);
        printf("\t%ld\n", currentNode->count);
    }


}

void freeRoot (node* root)
{
    if (root==NULL) return;
        for (int i = 0; i < NUM_LETTES; i++)
    {
        freeRoot(root->children[i]);
    }
free(root);
}
