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

void split(Node *&in, Node *&odds, Node *&evens)
{
    /* Add code here */
    // WRITE YOUR CODE HERE
    // check if anything is in the list to begin with
    if (in == nullptr)
    {
        return;
    }
    // check if value is even
    if (in->value % 2 == 0)
    {
        // stores temp node
        Node *tempE = in;
        // starts in after the first one
        in = in->next;
        // temp next to add evens at end of the list
        tempE->next = evens;
        // update even head to be temp
        evens = tempE;
        // recursive call
        split(in, odds, evens->next);
    }
    // check if value is odd
    else
    {
        // same as even but for odd
        Node *tempO = in;
        in = in->next;
        tempO->next = odds;
        odds = tempO;
        split(in, odds->next, evens);
    }
}

/* If you needed a helper function, write it here */
