#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node* left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* delete(node* root, int key)
{ 
    if (root == NULL)
    {
        return;
    }

    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->data = delete (root->data, temp >->key);
    }
    return root;
}

node *inordersucc(node *root)
{
    node *root = curr;
    while (curr && curr-> left != NULL)
    {
        curr = curr-> left;
    }

}
Node* inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

int main()
    {
        Node* root = new Node(4);
        root->left= new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        root->right->right = new Node(6);

        inorder(root);
        cout<<endl;
        root= delete(root,5);
        inorder(root);


        inorder(root);
        cout << endl;
}