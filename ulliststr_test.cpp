/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"
#include <string>


int main(int argc, char* argv[])
{
  ULListStr list; //creates new ULListStr class called "list"

  //cout<<"Current back: "<<list.back()<<endl;
  //cout<<"Current front: "<<list.front()<<endl;
  cout<<"Current size: "<<list.size()<<endl;
  
  for(int i=0; i<15; i++)     //adding odd numbers to the back, even to the front
  {
    list.push_back(to_string(i*3));      //first push is from back, on empty list
    cout<<"Current back: "<<list.back();

    list.push_front(to_string(i*2));
    cout<<" Current front: "<<list.front();
    cout<<" Current size: "<<list.size()<<endl;
  }
  cout<<"End of pushing"<<endl;

  list.set(20,"100");
  cout<<"Index 20 is now: "<<list.get(20)<<endl;

  for(int i=0; i<15; i++)     //pop all the numbers in the list out
  {
    list.pop_back();
    cout<<"Current back: "<<list.back();

    list.pop_front();       //last pop is from front
    cout<<" Current front: "<<list.front();
    cout<<" Current size: "<<list.size()<<endl;
  }
  cout<<"End of popping"<<endl;

  if(list.size()==0) //priv, use size()
  {
    cout<<"Size empty"<<endl;
  }
  else
  {
    cout<<"more to pop"<<endl;
  }

  list.push_front("19");
  cout<<"Current front: "<<list.front()<<endl;
  list.pop_back();
  cout<<"Current size: "<<list.size()<<endl;

  return 0;
}
