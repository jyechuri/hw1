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

// Note: Important to check if there's one node, multiple or none! (3 cases)
// getValAtLoc
std::string *ULListStr::getValAtLoc(size_t loc) const
{
    // if location is greater than the size then it does not exist
    if (loc >= size_ || size < 0)
    {
        return nullptr;
    }
    else
    {
        Item *currNode = head_;
        int currVal = 0;
        // traverse through the nodes
        while (currNode != nullptr)
        {
            // traverese through each array list in the node
            for (int i = currNode->first; i < currNode->last; i++)
            {
                // return the value at location in node
                if (loc == currVal)
                {
                    return &(currNode->val[i]);
                }
                currVal++;
            }
            // traverse through thr nodes
            currNode = currNode->next;
        }
        return nullptr;
    }
}

void ULListStr::push_back(const std::string &val)
{

    // case of 0
    if (empty())
    {
        Item *newNode = new Item();
        head_ = newNode;
        tail_ = newNode;
        // increase accordinly
        newNode->val[0] = val;
        newNode->last++;
    }
    // case more than one with tail full
    else if (tail_->last == ARRSIZE)
    {
        // new node created
        Item *newNode = new Item();
        newNode->val[0] = val;
        newNode->last++;

        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }
    else
    {
        // add to end of current array
        tail_->val[tail_->last] = val;
        tail_->last++;
    }
    // size inc
    size_++;
}

void ULListStr::push_front(const std::string &val)
{
    // add if empty
    if (empty())
    {
        Item *newNode = new Item();
        head_ = newNode;
        tail_ = newNode;
        // update accordingly
        newNode->val[0] = val;
        newNode->last++;
    }
    // add node ahead if current node is full
    else if (head_->first == 0)
    {
        Item *newNode = new Item();
        newNode->next = head_;
        newNode->val[ARRSIZE - 1] = val;
        newNode->first = ARRSIZE - 1;
        newNode->last = ARRSIZE;

        head_->prev = newNode;
        head_ = newNode;
    }
    // add if head is not full
    else
    {
        head_->val[head_->first - 1] = val;
        head_->first--;
    }
    size_++;
}

// CHECKTHIS
void ULListStr::pop_back()
{
    // case of 0 in list
    if (empty())
    {
        return;
    }
    // only one node in linked list
    if (size_ == 1)
    {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
    }
    // only one element left in list
    else if (tail_->last == 1)
    {
        Item *victim = tail_;
        tail_ = victim->prev;
        delete victim;
        victim = nullptr;
        tail_->next = nullptr;
    }
    // case of multiple in array
    else
    {
        tail_->last--;
    }
    size_--;
}

// CHECK THISSSS!
void ULListStr::pop_front()
{
    // empty linked list
    if (empty())
    {
        return;
    }
    // only one node in linked list
    if (size_ == 1)
    {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    }
    // only one element in arr
    else if (head_->first == ARRSIZE - 1)
    {
        Item *victim = head_;
        head_ = victim->next;
        delete victim;
        victim = nullptr;
        head_->prev = nullptr;
    }
    // update first if multiple item
    else
    {
        head_->first++;
    }
    size_--;
}

/* Returns a reference to the last value in the list.
  Calling this on an empty list causes undefined behavior.*/
std::string const &ULListStr::back() const
{
    return tail_->val[tail_->last - 1];
}
/* Returns a reference to the first value in the list.
  Calling this on an empty list causes undefined behavior.*/
std::string const &ULListStr::front() const
{
    return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string &val)
{
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL)
    {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string &ULListStr::get(size_t loc)
{
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL)
    {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const &ULListStr::get(size_t loc) const
{
    std::string *ptr = getValAtLoc(loc);
    if (ptr == NULL)
    {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while (head_ != NULL)
    {
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}
