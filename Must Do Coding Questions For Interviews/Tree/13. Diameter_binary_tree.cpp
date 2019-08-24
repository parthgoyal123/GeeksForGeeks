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
/* Computes the diameter of binary tree with given root.  */


// modified height function that also calculates diameter
int height(Node* root, int &dia) {
    if(!root) return 0;
    
    // calculate left and right heights
    int left_height = height(root->left, dia);
    int right_height = height(root->right, dia);
    
    // make a path and check its length
    dia = max(left_height + right_height + 1, dia);
    
    // return the normal height of the node
    return max(left_height, right_height) + 1;
}

int diameter(Node* node) {
    
    // if no node
    if(!node) return 0;
    
    int max_diameter = INT_MIN;
    
    height(node, max_diameter);
    
    return max_diameter;
}
