#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcpointer(Node *root, Node **first, Node **last, Node **mid, Node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calcpointer(root->left, first, last, mid, prev);
    // ab hum left subtree ko travers karke vapis aa gye ab hum cheak karna hai ki propertiy voilet kar rhi hai
    // nahi aur kar rhi hai to which time first time yaaa second time -
    if (*prev && root->data < (*prev)->data)
    {
        // yadi first time voilet ho rhi hogi to first hoga NULL
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcpointer(root->right, first, last, mid, prev);
}
void restore(Node* root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcpointer(root, &first, &mid, &last, &prev)
    {
        // case 1
        if (first && last)
        {
            swap(&(first->data), &(last->data));
        }
        else if (first && mid)
        {
            swap(&(first->data), &(mid->data));
        }
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    restore(root);
    inorder(root);
    cout<<endl;
}