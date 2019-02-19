#include "defs.h"

Node* NewNode(int value){
  Node* node = (Node*)malloc(sizeof(Node));
  if(node == NULL){
    printf("***NODE ALLOCATION FAILURE");
    exit(-1);
  }
  node->forward_link=NULL;
  node->backward_link=NULL;
  node->isDummy = 0;
  node->value = value;
  return node;
}

List* NewList(){
  List* list = (List*)malloc(sizeof(List));
  if(list == NULL){
    printf("***LIST ALLOCATION FAILURE***");
    exit(-1);
  }
  list->head = NewNode(-1);
  list->tail = NewNode(-1);
  list->head->forward_link = list->tail;
  list->tail->backward_link = list->head;
  list->head->isDummy = 1;
  list->tail->isDummy = 1;
  list->size = 0;
  return list;
}

void PushFront(List* list, int value){
  Node* node = NewNode(value);
  node->forward_link = list->head->forward_link;
  node->backward_link = list->head;
  list->head->forward_link->backward_link = node;
  list->head->forward_link = node;
  list->size++;
}

void PushRear(List *list, int value){
  Node* node = NewNode(value);
  node->backward_link = list->tail->backward_link;
  node->forward_link  = list->tail;
  list->tail->backward_link->forward_link = node;
  list->tail->backward_link = node;
  list->size++;
}

int PopFront(List *list){
  Node* node = list->head->forward_link;
  int value = node->value;
  list->head->forward_link = node->forward_link;
  node->forward_link->backward_link = list->head;
  free(node);
  list->size--;
  return value;
}

void ForwardWalk(List *list){
  Node* node = list->head->forward_link;
  int counter = 1;
  while(node->isDummy == 0){
    printf("\nNode %d: %d", counter, node->value);
    counter++;
    node = node->forward_link;
  }
  if(counter == 1){
    printf("Empty List!\n");
  }
}