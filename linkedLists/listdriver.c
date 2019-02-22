#include "defs.h"

int main(){

  List* list = NewList();

  //assigning values for linked list
  for(int i = 10; i > 0; i--){
    PushFront(list, i);
  }

  //testing various functions
  InsertNode(list, 4, 16);
  InsertNode(list, 0, 12);
  EditNode(list, 11, 100);
  RemoveNode(list, 2);
  ForwardWalk(list);
  printf("\n");
  return 0;
}