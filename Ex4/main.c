#include <stdio.h>
#include "trie.h"

int main( int argc ,char *argv[])
{
  char string[NUM_MAX];

  int maxWord=0,saveMax=0;
   node *root = setNull();
   memset(root,0, sizeof(char));



       while(fgets(string, NUM_MAX, stdin))
       {
           int length=strlen(string);
         saveMax= makeTrie(string, root,length);
         if(maxWord<saveMax) maxWord=saveMax;
       }
      if(argc!=1)
       {
           printRootReverse(root,maxWord);
       }
       else
        {
           printRoot(root,maxWord);
        }
    freeRoot(root);
    fclose(stdin);

    return 0;
}
