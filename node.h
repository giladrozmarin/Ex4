#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
// use index to character
#define CHAR_TO_LEVEL(c) ((int)c + (int)'a')
// Alphabet size (# of symbols)
#define NUM_LETTERS ((int)26)

enum isWord{FALSE = 0,TRUE = 1};

//node defenition
typedef struct node
{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    enum isWord isEndOfWord;
} node;

node *newNode();
node *addNode(node *root, char letter);
int buildTrie(node *root);
void printTrie(const node *root, char str[], int level); 
void printTrieR(const node *root, char str[], int level);
void freeTrie(node *root);