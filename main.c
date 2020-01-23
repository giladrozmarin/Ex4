#include "node.h"
/**
 * This program build Trie data structer and print in alpha-bet order from start to and and with 'r' from end to start
 * 1.creat a root
 * 2.buildTrie(root)-build Trie data structer 
 * 3.if 'r' parm printTrieR(root, str, degree); 
 * 4.else printTrie(root, str, degree)
 * */
int main(int argc, char const *argv[])
{

  node *root = newNode();
  int maxWord =buildTrie(root);
  int degree = 0;
  char str[maxWord];

  if (argc > 1 && *(argv[1]) == 'r')
    printTrieR(root, str, degree); 
  else
    printTrie(root, str, degree); 

  freeTrie(root);
}