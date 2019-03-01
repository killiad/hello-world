#include "defs.h"

/*INPUT: Integer value to be stored in the list
  FUNCTION: Dynamically allocates a new node
  OUTPUT: list node*/
Node* NewNode(int value){
  Node* node = (Node*)malloc(sizeof(Node));

  if(node == NULL){
    printf("***NODE ALLOCATION FAILURE");
    exit(-1);
  }

  //initializing default state of node to be not connected to any list
  node->forward_link=NULL;
  node->backward_link=NULL;
  node->value = value;
  return node;
}

/*INPUT: void
  FUNCTION: Dynamically allocates a new, doubly-linked linear list
  OUTPUT: the newly allocated linked list*/
List* NewList(){
  List* list = (List*)malloc(sizeof(List));

  if(list == NULL){
    printf("***LIST ALLOCATION FAILURE***");
    exit(-1);
  }

  //initializing dummy head and tail nodes
  list->head = NewNode(-1);
  list->tail = NewNode(-1);
  list->head->forward_link = list->tail;
  list->tail->backward_link = list->head;
  list->size = 0;
  return list;
}