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
 
bool findNode(Node *root, int n, vector<Node*> &path) {
    
    // base check
    if(root == NULL) return false;
    
    // add this to path
    path.push_back(root);
    
    // check if this is the current node
    if(root->data == n) {
        return true;
    }
    
    // check in left and right subtree
    if((root->left && findNode(root->left, n, path)) || (root->right && findNode(root->right, n, path))) {
        return true;
    }
    
    // if not found in either, remove current node from the path
    path.pop_back();
    return false;
}

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/
Node * lca(Node* root ,int n1 ,int n2 ){
    
    // base check
    if(!root) return NULL;
    
    // get paths for n1 and n2
    vector<Node*> path1;
    vector<Node*> path2;
    
    // get paths to n1 and n2
    bool flag1 = findNode(root, n1, path1);
    if(!flag1) return NULL;
    
    
    bool flag2 = findNode(root, n2, path2);
    if(!flag2) return NULL;

    // iterate for size2
    int i = 0;
    for(i = 0; i<path1.size() && i<path2.size(); i++) {
        if(path1[i]->data != path2[i]->data) {
            break;
        }
    }
    
    return path1[i-1];
}