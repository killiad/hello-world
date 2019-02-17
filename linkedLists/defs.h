#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
  int value;
  struct node_s* forward_link;
  struct node_s* backward_link;
  _Bool isDummy;
} Node;

typedef struct list_t{
  int size;
  struct node_s* head;
  struct node_s* tail;
} List;

List* NewList();
Node* NewNode(int value);
void PushFront(List *list, int value);
