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
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node *&head, int val)
{
    node *temp = head;
    if (head == NULL)
        return;

    if (head->next)
    {
        deleteathead(head);
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

// reverse a linked list
node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
node *reverseRecursive(node *&head)
{
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
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
void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}
bool detectcycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
        ;
    {
        slow = head->next;
        fast = head->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
bool removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
    } while (fast != slow);
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = NULL;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertathead(head, 4);
    insertathead(head, 5);
    insertathead(head, 6);
    insertathead(head, 7);

    // cout<<search(head,2);
    // display(head);

    // deletion(head,3);
    // display(head);
    // deleteathead(head);
    // node* newhead = reverseRecursive(head);
    // display(newhead);
    // int k =2;
    // node* newhead=  reverseKnodes(head,k);
    // display(newhead);
    makecycle(head, 3);
    cout << detectcycle(head);
    removecycle(head);
    cout<<detectcycle(head);
    display(head);
    // display(head);
}