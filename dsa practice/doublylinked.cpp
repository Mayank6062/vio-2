#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node *&head1, int val)
{
    node *n = new node(val);
    n->next = head1;
    if (head1 != NULL)
    {
        head1->prev = n;
    }
    head1 = n;
}
void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *temp = head;
    node *n = new node(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteathead(node *head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node *head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
        return;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *kappend(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int l = length(head);
    int count = 1;
    k = k % l;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int intersect(node* &head1,node* &head2 ,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2 ->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp2;
}
int main()
{
    // node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;
    insertattail(head1, 1);
    insertattail(head1, 2);
    insertattail(head1, 3);
    insertattail(head1, 4);
    insertattail(head1, 5);
    insertattail(head1, 6);
    insertathead(head1, 9);
    insertathead(head1, 10);
    intersect(head1, head2 ,3);
    display(head1);
    display(head2);


    // deletion(head, 3);
    // display(head);
    // node *newhead = kappend(head, 3);
    // display(newhead);

    return 0;
}