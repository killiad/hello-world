#include "defs.h"

Node* newNode(int value){
  Node* node = (Node*)malloc(sizeof(Node));
  node->forward_link=NULL;
  node->backward_link=NULL;
  node->isDummy = 0;
  return node;
}

List* newList(){
  List* list = (List*)malloc(sizeof(List));
  if(list == NULL){
    printf("***LIST ALLOCATION FAILURE***");
    exit(-1);
  }
  list->head = newNode(-1);
  list->tail = newNode(-1);
  list->head->forward_link = list->tail;
  list->tail->backward_link = list->head;
  list->head->isDummy = 1;
  list->tail->isDummy = 1;
  list->size = 0;
  return list;
}
