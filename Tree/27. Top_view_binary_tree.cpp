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
void topView(Node *root);
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
     topView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data, hd;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(Node *root) {
    if(!root) return;
    
    queue<pair<Node*,int>> q;
    unordered_map<int,int> m;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {
        pair<Node*, int> top = q.front();
        q.pop();
        
        Node* node = top.first;
        int hd = top.second;
        
        if(m.find(hd) == m.end()) {
            m[hd] = 1;
            cout << node->data << " ";
        }
        
        if(node->left) q.push(make_pair(node->left, hd-1));
        if(node->right) q.push(make_pair(node->right, hd+1));
    }
    
}
