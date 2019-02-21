#include "defs.h"

int main(){

  List* list = NewList();
  
  //testing edge cases
  ForwardWalk(list);
  PopFront(list);
  
  //testing another edge case
  PushFront(list, 0);
  PopFront(list);
  ForwardWalk(list);

  //assigning values for linked list
  for(int i = 10; i > 0; i--){
    PushFront(list, i);
  }

  //testing various functions
  PushRear(list, 100);
  PushRear(list, 200);
  int rear = PopRear(list);
  ForwardWalk(list);
  PopRear(list);
  printf("\n\n");
  printf("Value popped from the rear was %d\n", rear);
  printf("List size is %d\n", list->size);
  BackwardWalk(list);
  printf("\n");
  return 0;
}