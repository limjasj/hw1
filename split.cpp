/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in ==nullptr)
  //if no more items left in the list, then return
  {
    return;
  }

  else if((in->value % 2 == 1) && (odds==nullptr))
  {
    //if odd then add node into "odds" list, iterate to next node in "in" list
    odds=in;
    in=in->next;

    //call function recursively
    split(in, odds, evens);
  }

  else if ((in->value % 2 == 0) && (evens==nullptr))
  {
    //if even then add node into "even" list, iterate to next node in "in" list
    evens=in;
    in=in->next;
    
    //call function recursively
    split(in, odds, evens);
  }

  else if(in->value % 2 == 1)
  {
    //if odd then add node into "odds" list, iterate to next node in "in" list
    odds->next= in;
    in=in->next;
    odds->next->next = nullptr;
    
    //call function recursively
    split(in, odds->next, evens);
  }

  else
  {
    //if even then add node into "even" list, iterate to next node in "in" list
    evens->next= in;
    in=in->next;
    evens->next->next = nullptr;
    
    //call function recursively
    split(in, odds, evens->next);
  }
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE