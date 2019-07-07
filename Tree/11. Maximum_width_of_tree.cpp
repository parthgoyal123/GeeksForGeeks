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
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Structure of a Binary Tree 
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
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    int max_width = 1;
    int count = 1;
    int prev_height = 0;
    
    while(!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();
        
        if(front.first->left != NULL) q.push(make_pair(front.first->left, front.second + 1));
        if(front.first->right != NULL) q.push(make_pair(front.first->right, front.second + 1));
        
        if(front.second == prev_height) {
            count++;
            if(count > max_width) {
                max_width = count;
            }
            
        } else {
            prev_height = front.second;
            count = 1;
        }
    }
    
    return max_width;
}
