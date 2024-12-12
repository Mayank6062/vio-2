#include <iostream>
#include <climits>
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

struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};
info largestbst(Node* root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    { //  yadi root ak leaf node hai to uske liye condition
        return {1, root->data, root->data, 1, true};
    }

    info leftinfo = largestbst(root->left);
    info rightinfo = largestbst(root->right);

    info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);
    if (leftinfo.isbst && rightinfo.isbst && leftinfo.max < root->data && rightinfo.min > root->data){
    curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
    curr.max = max(rightinfo.max, max(leftinfo.max, root->data));

    curr.ans = curr.size;
    curr.isbst =true;
    return curr;
    }

    // yadi curr node bst nahi hai tab -- 
    curr.ans = max(leftinfo.ans ,rightinfo.ans);
    curr.isbst= false;
    return curr;
}
int main(){
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right  = new Node(30);
    root->left->left =new Node(5);

    cout<<"Largest bst is : "<<largestbst(root).ans<<endl;
    return 0 ;
}