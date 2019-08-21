#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int findDist(Node* ,int ,int );
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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/
   
   
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

bool findNode(Node* root, int n, int &length) {
    
    // base check
    if(root == NULL) return false;
    
    // include in path
    length += 1;
    
    // check if this is the node
    if(root->data == n) {
        return true;
    }
    
    // check in left and right subtree
    if((root->left && findNode(root->left, n, length)) || (root->right && findNode(root->right, n, length))) {
        return true;
    }
    
    length--;
    return false;
}  
 
int findDist(Node* root, int a, int b) {
    
    // base check
    if(root == NULL) return -1;
    
    // check if a != b or not
    if(a == b) return 0; // distance b/w a node with itself
    
    // find nodes a and b
    int distA = 0, distB = 0;
    bool flagA = false, flagB = false;
    
    flagA = findNode(root, a, distA);
    if(!flagA) return -1; // node a not found
    
    flagB = findNode(root, b, distB);
    if(!flagB) return -1; // node b not found
    
    Node* _lca = lca(root, a, b);
    
    // find distance of lca
    int distLCA = 0;
    bool flagLCA = false;
    
    // find the distance of LCA from root
    flagLCA = findNode(root, _lca->data, distLCA);
    if(!flagLCA) return -1;
    
    return (distA + distB - 2*distLCA);
    
}