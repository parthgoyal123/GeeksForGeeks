//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int minLeafSum(Node* root);
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
     cout<<minLeafSum(root)<<endl;
  }
  return 0;
}
// Contributed by: Harshit Sidhwa

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
int minLeafSum(Node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    
    queue<Node*> q;
    q.push(root);
    int count = 0; 
    bool flag = false;
    
    while(!q.empty()) {
        int curr_size = q.size();
        
        while(curr_size--) {
            Node *top = q.front();
            q.pop();
            if(top->left == NULL && top->right == NULL) {
                count += top->data;
                flag = true;
            }
            
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
        }
        
        if(flag) break;
    }
    
    while(!q.empty()) {
        q.pop();
    }
    
    return count;
}