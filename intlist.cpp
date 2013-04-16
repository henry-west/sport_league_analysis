/** author: Henry West
 * date: 15 April, 2013
 * description: the implementation of intlist.h
 */
#include "intlist.h"
#include <iostream>

using namespace std;

//constructor
IntList::IntList()
{
    head = NULL;
}

/*
 * function printList
 * no return, prints a linked list to the console
 */
void IntList::printList()
{
    ListNode *curr = head;
    while(curr)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

/*
 * function appendToList
 * no return, adds a param value to the end of a list
 */
void IntList::appendToList(int newValue)
{
    ListNode * myNewNode = new ListNode;
    myNewNode->value = newValue;
    myNewNode->next = NULL;

    ListNode * curr = head;

    if(head == NULL)
    {
        head = myNewNode;
    }
    else
    {
        while(curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next  = myNewNode;
    }
}

/*
 * function prependToList
 * no return, adds a param value to the beginning of a linked list
 */
void IntList::prependToList(int newValue)
{
    ListNode * myNewNode = new ListNode;
    myNewNode->value = newValue;
    myNewNode->next = NULL;

    ListNode * temp = head;
    head = myNewNode;
    myNewNode->next = temp;

}
/*
 * function insertInOrder
 * no return, adds a param value into a linked list in numerical order
 */
void IntList::insertInOrder(int newValue)
{
    ListNode * myNewNode = new ListNode;
    myNewNode->value = newValue;
    myNewNode->next = NULL;

    ListNode *curr;
    ListNode *prev;

    curr = head;
    prev = NULL;

    while(curr && curr->value < newValue)
    {
        prev = curr;
        curr = curr->next;
    }


    if(prev == NULL)
    {
        prependToList(newValue);
        delete myNewNode;
        //head = myNewNode;
        //myNewNode->next = curr;
    }
    else
    {
        /*if(curr == NULL)
        {
            //appendToList(newValue);
            //delete myNewNode;
            prev->next = myNewNode;
        }
        else
        {*/
            prev->next = myNewNode;
            myNewNode->next = curr;
        //}
    }
}
/*
 * function size
 * int return, returns the number of items in a linked list
 */
int IntList::size() {
    ListNode *curr;
    curr = head;
    int counter = 0;
    while (curr) {
        counter++;
        curr = curr->next;
    }
    return counter;
}
/*
 * function contains
 * bool return, returns whether or not a linked list contains a param element
 */
bool IntList::contains(int team) {
    ListNode *curr;
    curr = head;
    while (curr && curr->value != team) {
        if (curr->value == team) {
            return true;
        }
        else {
            curr = curr->next;
        }
    }
    return false;
}

//destructor
IntList::~IntList()
{
    ListNode *curr;
    ListNode *prev;

    curr = head;

    while(curr)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }

}
