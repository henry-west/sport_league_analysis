#ifndef INTLIST_H
#define INTLIST_H


class IntList
{
private:
    struct ListNode
    {
        int value;
        ListNode * next;
    };
    ListNode * head;

public:
    IntList();
    ~IntList();
    void printList();
    void appendToList(int);
    void prependToList(int);
    void insertInOrder(int);
    int size();
    bool contains(int);
};

#endif // INTLIST_H
