#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *reverseKnodes(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverseKnodes(nextptr, k);
    }
    return prevptr;
}

int main()
{
    node *head = NULL;
    int k = 2;
    node *newhead = reverseKnodes(head, k);
    // display(newhead);
    return 0;
}