#include <iostream>
#include <vector>
using namespace std;

int catalan(int n)
{

    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << "  ";
    }
    cout << endl;
    return 0;
}

time complexity = o(bahut jyda ) this can solve using recursive method
this is not practical

application if catalan number

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
vector<Node*> Construct(int start, int end)
{

    
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftsubtrees = Construct(start, i - 1);
        vector<Node *> rightsubtress = Construct(i + 1, end);

        for (int j = 0; j < leftsubtrees.size(); j++)
        {
            Node *left = leftsubtrees[j];
            for (int k = 0; k < rightsubtress.size(); k++)
            {
                Node *right = rightsubtress[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<Node *> totaltrees = Construct(1, 3);
    for (int i = 0; i < totaltrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(totaltrees[i]);
        cout << endl;
    }
}