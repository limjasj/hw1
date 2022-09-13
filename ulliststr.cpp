#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val)
{
  if(size_==0)    //if empty, then create a new Item
  {
    Item* temp=new Item;   //creates a dynamically allocated item temp
    temp->next=nullptr;       //sets temp's next pointer to null
    temp->val[0]=val;      //places function input(val) into temp  
    temp->first=0;         //set first to 0, last to 1
    temp->last=1;

    temp->prev=nullptr;
    head_=temp;
    tail_=temp;

    //delete temp;
  }
  else //not empty
  {
    if((tail_->last)!=10) //if last index in array is available
    {
      //find last index and put val inside it
      tail_->val[tail_->last]=val;
      tail_->last=(tail_->last)+1;
    }
    else if (tail_->last==10)     //if something is in last index
    {
      Item* temp=new Item;   //creates a dynamically allocated item temp
      temp->next=nullptr;       //sets temp's next pointer to null
      temp->val[0]=val;      //places function input(val) into temp  
      temp->first=0;         //set first to 0, last to 1
      temp->last=1;

      temp->prev=tail_;      //sets temp's prev pointer to tail
      tail_->next=temp;     //sets tail's next to temp
      tail_=temp;           //temp is the new tail

      //delete temp;
    }
  }
  size_+=1;

}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back()
{
  if(size_>0) //if the Item list is not empty
  {
    size_-=1;             //decrement size
    if(tail_->last==1)    //if there's only one element in tail Item
    {
      if(tail_->prev==nullptr) //only one item
      {
        delete tail_;
      }
      else    //more than one item
      {
        tail_=tail_->prev;
        delete tail_->next;
        tail_->next=nullptr;
      }
    }
    else      //if there's multiple elements in tail Item
    {
      //tail_->val[tail_->last]=nullptr;      //delete current last / make the space in the "last" pointer NULL
      tail_->last=(tail_->last)-1;  //increment "last" pointer in val
      
    }
  }
}
 
/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val)
{
  if(size_==0) //if entire thing is empty
  {
    Item* temp=new Item;   //creates a dynamically allocated item temp
    temp->prev=nullptr;       //sets temp's prev pointer to null
    temp->val[9]=val;      //places function input(val) into temp's last index 
    temp->first=9;         //set first to 9, last to 10
    temp->last=10;

    temp->next=nullptr;    //set both head and tail to temp
    head_=temp;
    tail_=temp;
 
    //delete temp;
  }
  else //the entire thing is not empty
  {
    if(head_->first!=0)     //if the first index is available
    {
      //find first index and put val inside it
      head_->val[(head_->first)-1]=val;
      head_->first=(head_->first)-1; //subtract from first's value
    }
    else if (head_->first==0)  //the first index is not available
    {
      Item* temp=new Item;   //creates a dynamically allocated item temp
      temp->prev=nullptr;       //sets temp's prev pointer to null
      temp->val[9]=val;      //places function input(val) into temp's last index 
      temp->first=9;         //set first to 9, last to 10
      temp->last=10;

      temp->next=head_;      //sets temp's prev pointer to tail
      head_->prev=temp;     //sets tail's next to temp
      head_=temp;           //temp is the new head
      
      //delete temp;
    }
  }
  size_+=1;
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
  if(size_>0)
  {
    size_-=1;             //decrement size
    if(head_->first==9)    //if there's only one element left in head Item
    {
      if(head_->next==nullptr)  //if head is the only Item, then make head and tail null
      {
        delete head_;
      }
      else 
      {
        head_=head_->next;
        delete head_->prev;
        head_->next=nullptr;
      }
    }
    else      //if there's multiple elements in head Item
    {
      //head_->val[head_->first]=NULL;      //delete current first / make the space in the "first" pointer NULL
      head_->first=(head_->first)+1;  //increment "first" pointer in val
    }
  }
}
  
/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const
{
  return tail_->val[(tail_->last)-1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc<size_) //index must be smaller than total size
  {
    Item* temp;  //create new item temp
    temp=head_;             //make the temp as head (beginning of data)
    size_t findLoc=temp->first;       //create new item temp

    for(unsigned int i=0; i<=loc; i++)
    {
      if(findLoc==9)
      {
        temp=temp->next;
        findLoc=temp->first;
      }
      else
      {
        findLoc++;
      }
    }

    return &temp->val[findLoc]; //need item address, val address
  }

  else 
  {
    return nullptr;
  }
}

