/*
Problem#10 - (Extended of problem 9)
We extended previous Problem by adding extra queries:
This problem is simple. Initially, there is a list and it's empty. Then you are given four types of query.
1. Insert data to the list
2. Remove data from the list
3. Print an index (1-based) from a specified data after the list was sorted ascendingly
4. Print data from a specified index (1-based) after the list was sorted ascendingly
We want to make insertion, deletion, getting operations in O(log2
(n))
Input
Input contains several lines. Each line follows one of these formats.
1 n: Insert n (0 <= n <= 231
- 1) to the list
2 n: Remove n from the list. If n was not found, do nothing
3 n: Print n's index (1-based) after the list was sorted ascendingly
4 i: Print data on i-th index (1-based) after the list was sorted ascendingly (0 <= i <= 231
- 1)
-1: End of input
Output
For each query 3, print n's index in one line. If n was not found, just print -1
For each query 4, print data on i-th index in one line. If the index is not valid, just print -1
*/



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


int counter =1;
int search_position (Node*root,int key){

     if(root!=NULL)
  {  if (root->key == key)
       {
           counter++;
           return counter;
       }
    else if (root->key< key)
       {
           counter++;
           search_by_key(root->right, key);

       }else
         {
             counter++;
             search_by_key(root->left, key);
        }
}
}


/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.

Node* deleteNode(Node* root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + Max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//for 4
int arr[3];
int j =0;
int* preOrder(Node *root)
{
    if(root != NULL)
    {
        arr[j] =root->key;
        j++;
        preOrder(root->left);
        preOrder(root->right);
    }
    return arr;

}

find_by_index (Node* root , int index)
{
    int* arr  ;
    arr = preOrder(root);
    for (int i =0;i<3;i++){
        if ((index) == i && (index+1<=3))
            cout<<arr[index]<<endl;
    }


}
// Driver Code
int main()
{
    Node *root = NULL;
    int op;
    int numofoperations;
    cout<<"enter the number of operations you will do\n";
    cin>>numofoperations;
    for (int i =0;i<numofoperations;i++){
        cout<<"enter your option \n 1 for insertion \n 2 for removing \n 3 for index \n 4 for data\n";\
        cin>>op;
        switch (op) {
        case 1:
            {
                int x;
                cout<<"enter the number to insert\n";
                cin>>x;
                root=Insert(root,x);
                break;
            }
        case 2:
            {
                int x;
                cout<<"enter the number to remove \n";
                cin>>x;
                bool flag = search_by_key(root,x);
                if(flag)
                root = deleteNode(root,x);
                else
                    cout<<"-1 \n";
                break;
            }
        case 3:
            {
                int x;
                cout<<"enter the number to search for \n";
                cin>>x;
                int c;
                c = search_position(root,x);
                if (c==0) cout<<"-1"<<endl;
                    else
                cout<<c<<endl;
                break;

            }
        case 4:
            {int x;
            cout<<"enter the index\n";
            cin>>x;
             find_by_index(root,x);
             break;
            }
        case -1:
            i = numofoperations-1;
            break;

        }
    }
    return 0;
}
