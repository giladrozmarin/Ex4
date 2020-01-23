#include "node.h"

int main(int argc, char const *argv[])
{

  node *root = newNode();
  int maxWord = ((int)buildTrie(root));
  int degree = 0;
  char str[maxWord];

  if (argc > 1 && *(argv[1]) == 'r')
    printTrieR(root, str, degree); 
  else
    printTrie(root, str, degree); 

  freeTrie(root);
}