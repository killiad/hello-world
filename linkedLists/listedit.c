#include "defs.h"

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

/*INPUT: linked list name, position of desired node, new value of node
  FUNCTION: Edits the value of a desired node
  OUTPUT: void*/
void EditNode(List *list, int position, int new_value){
  if (0 < position && position <= list->size){
    Node *node = GoToNode(list, position);
    node->value = new_value;
  }
  else{
    printf("Position is out of bounds!");
  }
}

/*INPUT: linked list name, position of desired node, value for node
  FUNCTION: Inserts a new node anywhere in the linked list
  OUTPUT: void*/
void InsertNode(List *list, int position, int value){
   if (0 < position && position <= list->size){
     Node *node = NewNode(value);
     Node *pushedNode = GoToNode(list, position);
     node->forward_link = pushedNode;
     node->backward_link = pushedNode->backward_link;
     pushedNode->backward_link->forward_link = node;
     pushedNode->backward_link = node;
     list->size++;
   }
   else{
     printf("Position is out of bounds!");
   }
}

/*INPUT: linked list named, position of desired node
  FUNCTION: removes any node from the linked list
  OUTPUT: integer value of removed node*/
int RemoveNode(List *list, int position){
  if (0 < position && position <= list->size){
    Node *poppedNode = GoToNode(list, position);
    int value = poppedNode->value;
    poppedNode->forward_link->backward_link = poppedNode->backward_link;
    poppedNode->backward_link->forward_link = poppedNode->forward_link;
    free(poppedNode);
    list->size--;
    return value;
  }
  else{
     printf("Position is out of bounds!");
     return -1;
   }
}