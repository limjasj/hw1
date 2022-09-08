#include "split.h"

int main()
{
  Node *six= new Node(6, nullptr);
  Node *five= new Node(5, six);
  Node *four= new Node(4, five);
  Node *three= new Node(3, four);
  Node *two= new Node(2, three);
  Node *one= new Node(1, two);
  

  Node *evens=nullptr;
  Node *odds=nullptr;

  split(one, evens, odds);

  while(evens != nullptr) {
    Node* temp = evens;
    std::cout << evens ->value << std::endl;
    evens = evens ->next;
    delete temp;
  }

   while(odds != nullptr) {
    Node* temp = odds;
    std::cout << odds ->value << std::endl;
    odds = odds ->next;
    delete temp;
  }

  //passes in a reference to a pointer; one, oddNum, evenNum are pointers
}

/*
Issues:
- one -> value should not be null after calling split
- calling delete in while loop works but calling delete 
separately give valgrind errors

*/