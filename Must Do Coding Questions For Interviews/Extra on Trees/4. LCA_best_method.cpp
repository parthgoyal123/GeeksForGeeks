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
Node * lca(Node* ,int ,int );
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
    
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
     int a,b;
     cin>>a>>b;
     Node * k = lca(root,a,b);
     cout<<k->data<<endl;
  
  }
  return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
 */
 
Node * lcaUtil(Node* root ,int n1 ,int n2, bool &flag1, bool &flag2){
    
    // base check
    if(root == NULL) return root;
    
    // check if n1 and n2 are both equal
    if(root->data == n1 && root->data == n2) {
        flag1 = true, flag2 = true;
        return root;
    }
    
    // check for n1
    if(root->data == n1) {
        flag1 = true;
        return root;
    }
    
    // check for n2
    if(root->data == n2) {
        flag2 = true;
        return root;
    }
    
    // check for left and right subtrees
    Node *left = lcaUtil(root->left, n1, n2, flag1, flag2);
    Node *right = lcaUtil(root->right, n1, n2, flag1, flag2);
    
    // if n1 and n2 exists in left and right or vice-versa, the current root is LCA
    if(left && right) return root;
    
    // if only one of them exists
    return (left)? left:right;
}

// Returns true if key k is present in tree rooted with root 
bool find(Node *root, int k) { 
    // Base Case 
    if (root == NULL) 
        return false; 
  
    // If key is present at root, or in left subtree or right subtree, 
    // return true; 
    if (root->data == k || find(root->left, k) ||  find(root->right, k)) 
        return true; 
  
    // Else return false 
    return false; 
}

Node *lca(Node* root, int n1, int n2) {
    bool flag1 = false, flag2 = false;
    
    Node *lca = lcaUtil(root, n1, n2, flag1, flag2);
    
    // check for existence of both n1 and n2
    if((flag1 && flag2) || (flag1 && find(lca, n2)) || (flag2 && find(lca, n1))) return lca;
    
    return NULL;
}