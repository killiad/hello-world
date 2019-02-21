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

/*INPUT: linked list name, node value
  FUNCTION: Addes a new node to the front of the list
  OUTPUT: void*/
void PushFront(List* list, int value){
  Node* node = NewNode(value);
  node->forward_link = list->head->forward_link;
  node->backward_link = list->head;
  list->head->forward_link->backward_link = node;
  list->head->forward_link = node;
  list->size++;
}

/*INPUT: linked list name, node value
  FUNCTION: Addes a new node to the end of the list
  OUTPUT: void*/
void PushRear(List *list, int value){
  Node* node = NewNode(value);
  node->backward_link = list->tail->backward_link;
  node->forward_link  = list->tail;
  list->tail->backward_link->forward_link = node;
  list->tail->backward_link = node;
  list->size++;
}

/*INPUT: linked list name
  FUNCTION: Removes a node from the beginning of the list
  OUTPUT: integer value of the node popped*/
int PopFront(List *list){

  if(list->size < 1){
    printf("Cannot pop an empty list!\n");
    return -1;
  }

  Node* node = list->head->forward_link;
  int value = node->value;
  list->head->forward_link = node->forward_link;
  node->forward_link->backward_link = list->head;
  free(node);
  list->size--;
  return value;
}

/*INPUT: linked list name
  FUNCTION: Removes a node from the end of the list
  OUTPUT: integer value of the node popped*/
int PopRear(List *list){

  if(list->size < 1){
    printf("Cannot pop an empty list!\n");
    return -1;
  }
  
  Node *node = list->tail->backward_link;
  int value = node->value;
  list->tail->backward_link = node->backward_link;
  node->backward_link->forward_link = list->tail;
  free(node);
  list->size--;
  return value;
}

/*INPUT: linked list name
  FUNCTION: walks the list forward, printing out the value of each node
  OUTPUT: void*/
void ForwardWalk(List *list){
  Node* node = list->head->forward_link;
  int counter = 0;

  //walks list until we reach the end, which is given by the size of the list
  while(counter != list->size){
    printf("\nNode %d: %d", ++counter, node->value);
    node = node->forward_link;
  }

  //checks for an empty list
  if(list->size == 0){
    printf("Empty List!\n");
  }
}

/*INPUT: linked list name
  FUNCTION: walks the list backward, printing out the value of each node
  OUTPUT: void*/
  void BackwardWalk(List *list){
    Node *node = list->tail->backward_link;
    int counter = 0;

    //walks list until we reach the end, which is given by the size of the list
    while(counter != list->size){
      printf("\nNode %d: %d", list->size - counter++, node->value);
      node = node->backward_link;
    }

    //checks for an empty list
    if(list->size == 0){
    printf("Empty List!\n");
  }
}