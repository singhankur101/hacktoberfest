//ok
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
  int weight;
  node* next;
}node;

int main(void)
{
  node* HEAD = NULL;
  node* last_node = NULL;

  for (int i = 0; i < 10; i++)
  {
    node* temp = (node*) malloc(sizeof(node));
    if (HEAD == NULL)
    {
      temp->weight = i+10;
      temp->next = NULL;
      HEAD = temp;
      last_node = temp;
    }
    else
    {
      last_node->next=temp;
      temp->weight = i;
      temp->next = NULL;
    }
  }

  node* crawler = HEAD;
  while (crawler!= NULL)
  {
    int val = crawler->weight;
    cout << "val: " << val << endl;
    crawler =crawler->next;
  }
  return 0;
}
