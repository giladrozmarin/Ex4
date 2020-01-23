#include "node.h"


node *newNode()//creat new node
{

  node *pNode;
  pNode = (node *)malloc(sizeof(node)); //Memory Allocation
                                        //Initialize
  pNode->letter = 0;
  pNode->count = 0;
  for (size_t i = 0; i < NUM_LETTERS; i++)
    pNode->children[i] = NULL;
  return pNode;
}


node *addNode(node *root, char letter)//add node
{
  node *adNode;
  adNode = newNode(); //init node
  adNode->letter = letter;
  adNode->isEndOfWord = FALSE;
  root->children[letter - 'a'] = adNode;
  return adNode; 
};
/**
 * This function build the TRIE data structure.
 * */
int buildTrie(node *root)
{
  int maxLengthWord = 0;//The longest word
  int tempMax = 0;
  int index; //Put the charcter we get in the right index array
  char c = ' ';
  while (scanf("%c", &c) != EOF)

  {
    node *aNode = root; //ask to root adress
    while (97 <= c && c <= 122)//check that we get letter case 
    {
      index = CHAR_TO_INDEX(c);
      if (aNode->children[index] == 0) //check that this is the first letter son
      {
        node *bNode = addNode(aNode, c); //add letter son to the father node
        aNode = bNode; //keep father root
        scanf("%c", &c);//take the next charcter
        tempMax++;//add 1 to word length
      }
      else
      {
        aNode = aNode->children[index]; //get insinde the tree
        scanf("%c", &c);//take the next charcter
        tempMax++;//add 1 to word length
      }
    }
    aNode->isEndOfWord = TRUE; //If we get here  so this is end of the word
    if (tempMax >= maxLengthWord)
    {
      maxLengthWord = tempMax;
    }
    tempMax = 0;
    aNode->count++;
  }
  root->isEndOfWord = FALSE;
  root->count = 0;
  return maxLengthWord;
}
/*
* printTrie function get: root adress, char array and empty level
* and  print Trie structer by alpha bet order  by recursion     
* 
*/
void printTrie(const node *root, char str[], int degree)
{
  if (root->isEndOfWord)
  {
    str[degree] = '\0';
    printf("%s", str);
    printf(" %lu\n", root->count);
  }

  int i;
  //check every child and send the relevant children to printTrie(root->children[i], str, level + 1))
  for (i = 0; i < NUM_LETTERS; i++)
  {
    if (root->children[i])
    {
      str[degree] = CHAR_TO_LEVEL(i);
      printTrie(root->children[i], str, degree + 1);
    }
  }
}
/*
*that work like printTrie just from the end to the beginning
*
*
*/
void printTrieR(const node *root, char str[], int degree)
{
  int i;
  for (i = NUM_LETTERS - 1; i >= 0; i--)
  {
    if (root->children[i])
    {
      str[degree] = CHAR_TO_LEVEL(i);
      printTrieR(root->children[i], str, degree + 1);
    }
  }

  if (root->isEndOfWord)
  {
    str[degree] = '\0';
    printf("%s", str);
    printf(" %lu\n", root->count);
  }
}

void freeTrie(node *root)
{
  if (root != NULL)
  {
    for (int i = 0; i < NUM_LETTERS; i++)
      freeTrie(root->children[i]);
    free(root);
  }
}
