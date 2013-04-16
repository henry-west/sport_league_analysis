#include "intlist.h"
#include <iostream>

using namespace std;


IntList::IntList()
{
    head = NULL;
}


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


void IntList::prependToList(int newValue)
{
    ListNode * myNewNode = new ListNode;
    myNewNode->value = newValue;
    myNewNode->next = NULL;

    ListNode * temp = head;
    head = myNewNode;
    myNewNode->next = temp;

}


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
