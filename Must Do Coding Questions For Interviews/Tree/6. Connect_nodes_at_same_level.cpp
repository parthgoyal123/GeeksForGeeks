#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};
void connect(struct Node *p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      cout<<node->data<<" ";
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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
     connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *root) {
    
    // base conditions
    if(!root) return;
    if(!root->left && !root->right) return;
    
    // make bfs queue (for level order traversal)
    queue<Node*> q;
    
    q.push(root);
    
    // level order traversal, iterate until queue is not empty
    while(!q.empty()) {
        
        int curr_size = q.size();
        Node* prev = NULL;
        
        while(curr_size--) {
            Node* top = q.front();
            q.pop();
            
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            
            if(prev != NULL) prev->nextRight = top;
            
            prev = top;
        }
    }
}
