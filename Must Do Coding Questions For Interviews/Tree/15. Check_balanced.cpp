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
bool isBalanced(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
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
     cout << isBalanced(root) << endl;
  }
  return 0;

}

/* modify the height function to check for every subtree*/
int height(Node* root, bool &flag) {
    
    // for 0 or 1 node
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    
    int leftH = height(root->left, flag);
    int rightH = height(root->right, flag);
    
    // if height was unbalanced at left or right subtree, return
    if(leftH == INT_MIN || rightH == INT_MIN) return INT_MIN;
    
    // if subtrees are balanced, check for this node
    if(abs(leftH-rightH) > 1) {
        flag = false;
        return INT_MIN;
    } 
    
    // if this tree is also balanced
    else {
        return max(leftH, rightH) + 1;
    }
}

/* check if tree is balanced or not*/
bool isBalanced(Node *root) {
    
    // flag denotes that tree is balanced at every subtree level
    bool flag = true;
    
    height(root, flag);
    
    return flag;
}
