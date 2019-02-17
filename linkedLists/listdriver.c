#include "defs.h"

int main(){

  List* list = NewList();
  ForwardWalk(list);
  PushFront(list, 0);
  PopFront(list);
  ForwardWalk(list);
  for(int i = 1; i <= 10; i++){
    PushFront(list, i);
  }
  ForwardWalk(list);
  printf("\n");
  return 0;
}
