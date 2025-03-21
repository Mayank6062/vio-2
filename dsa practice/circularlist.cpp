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
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void deleteathead(node* &head){
    node* temp = head ;
    while(temp->next != head){
        temp = temp ->next ;
    }
    node* todelete = head ;
    temp ->next = head ->next ;
    head = head->next;
    delete todelete;
}
void deletion(node* &head , int pos){
    if(pos==1){
        deleteathead(head);
        return ;
    }
    node* temp = head ;
    int count =1;
    while(count != pos-1){
        temp = temp->next ;
        count++ ;
    }
    node* todelete = temp->next ;
    temp->next = temp->next->next ;
    delete todelete ;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void evenafterodd(node* &head){
    node* odd = head ;
    node* even = head->next ;
    node* evenstart = even ;
    while(odd->next != NULL & even->next != NULL){
        odd->next = even->next;
        odd= odd->next;
        even->next = odd->next ;
        even = even->next;
    }
    odd->next = evenstart;
    if(odd->next != NULL){
        even->next = NULL;
    }
}

int main()
{
    node *head = NULL;
    // insertattail(head, 1);
    // insertattail(head, 2);
    // insertattail(head, 3);
    // insertathead(head, 4);
    // insertathead(head, 5);
    // insertathead(head, 6);
    // insertathead(head, 7);
    // display(head);
    // insertathead(head, 5);
    // display(head);
    // deletion(head,5);
    // display(head);
    int arr[] = {1,2,3,4,5,6};
    for(int i =0 ; i<6 ; i++){
        insertattail(head , arr[i]);
    }
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}