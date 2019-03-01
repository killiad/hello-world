#include "defs.h"

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

/*INPUT: linked list name, position of desired node
  FUNCTION: walks list efficiently to find desired node
  OUTPUT: node pointer to desired node*/
Node* GoToNode(List *list, int position){
  int counter = 0;

  if(position > list->size || position < 1){
    printf("Position out of bounds!\n");
    return list->tail;
  }

  else if(position*2 <= list->size){
    Node *node = list->head;
    while(counter != position){
      node = node->forward_link;
      counter++;
    }
    return node;
  }

  else{
    Node *node = list->tail;
    position = list->size - position + 1;
    while(counter != position){
      node = node->backward_link;
      counter++;
    }
    return node;
  }
}