/*
Problem#9
1) In this problem you are given two type of query
1. Insert an integer to the list.
2. Given an integer x, you're about to find an integer k which represent x's index if the list is sorted in
ascending order. Note that in this problem we will use 1-based indexing.
As the problem title suggest, this problem intended to be solved using O(log2
(n)) for both insertion and
getting X’s index
Input
The first line contains an integer Q, which denotes how many queries that follows. The next Q lines will be
one of the type queries which follow this format:
1 x means insert x to the list
2 x means find x's index if the list is sorted in ascending order.
Output
For each query type 2, print a line containing an integer as the answer or print "-1" no quotes if the requested
number does not exist in the current list
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to get maximum
// of two integers
int Max(int a, int b);

// A utility function to get the
// height of the tree
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int Max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = Max(height(y->left),
                    height(y->right)) + 1;
    x->height = Max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = Max(height(x->left),
                    height(x->right)) + 1;
    y->height = Max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* Insert(Node* node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = Insert(node->left, key);
    else if (key > node->key)
        node->right = Insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + Max(height(node->left),
                        height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

bool b=false;
bool search_by_key( Node* root, int key)
{
         if(root!=NULL)
  {  if (root->key == key)
       {
           b=true;
       }
    else if (root->key< key)
       {
           search_by_key(root->right, key);
       }else
         {
             search_by_key(root->left, key);
         }
  }
  return b;
}



// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver Code
int main()
{
    Node *root = NULL;

    int numofinputs =0;
    int op =0; // 1 for insertion 2 for search
    int x = 0;
    cout<<"enter the number of operations you will enter \n";
    cin>> numofinputs;
    for (int i =0;i<numofinputs;i++){
        cout<<"enter 1 for insertion or 2 for searching\n";
        cin>>op;
        switch (op){
        case 1:
            {cout<<"enter the value you want to insert\n";
            cin>>x;
            root = Insert(root,x);
            break;
            }
        case 2:
            {
                cout<<"enter the value you want to search \n";
                cin>>x;
                bool flag = search_by_key(root,x);
                int Rank = (int)search_by_key(root, x) + 1;
                if (flag)
                cout<<Rank<<endl;
                else
                cout<<"-1"<<endl;
                break;

                }
        default:
            cout<<"invalid input\n";

        }

    }

    return 0;
}
