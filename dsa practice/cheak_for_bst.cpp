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

bool cheakbst(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftvalid = cheakbst(root->left, min, root);
    bool rightvalid = cheakbst(root->right, root, max);
    return leftvalid and rightvalid;
}
int main(){
    Node* root =  new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    if(cheakbst(root , NULL , NULL)){
        cout<<"is_valid_Node";
    }
    else{
        cout<<"NOt";
    }
}

// time complexity = o(n);