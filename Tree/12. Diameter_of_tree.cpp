#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << diameter(root) << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


int height(Node *node, int &maximum) {
    
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return 1;

    int lh = height(node->left, maximum); int rh = height(node->right, maximum);

    int _height = max(lh, rh) + 1;    
    maximum = max(1+lh+rh, maximum);
    return _height;
}


/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node)
{
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return 1;
    
    int maximum = INT_MIN;
    int node_height = height(node, maximum);

    return maximum;
}



// int height(Node *node) {
    
//     if(node == NULL) return 0;
//     if(node->left == NULL && node->right == NULL) return 1;
    
//     return 1+max(height(node->left), height(node->right));
// }


// /* Computes the diameter of binary tree with given root.  */
// int diameter(Node* node)
// {
//     if(node == NULL) return 0;
//     if(node->left == NULL && node->right == NULL) return 1;
    
//     int lh = height(node->left);
//     int rh = height(node->right);
    
//     int maximum = lh+rh+1;
//     return max(max(maximum, diameter(node->left)), diameter(node->right));
// }