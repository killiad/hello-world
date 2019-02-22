#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
  int value;
  struct node_s* forward_link;
  struct node_s* backward_link;
} Node;

typedef struct list_t{
  int size;
  struct node_s* head;
  struct node_s* tail;
} List;

List* NewList();
Node* NewNode(int value);
void PushFront(List *list, int value);
void PushRear(List *list, int value);
int PopFront(List *list);
int PopRear(List *list);
void ForwardWalk(List *list);
void BackwardWalk(List *list);
Node* GoToNode(List *list, int position);
void EditNode(List *list, int position, int new_value);
void InsertNode(List *list, int position, int value);
int RemoveNode(List *list, int position);