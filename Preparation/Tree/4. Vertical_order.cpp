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
void verticalOrder(Node *root);
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
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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
void verticalOrder(Node *root) {
    
    // base conditions
    if(!root) return;
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    
    // map of horizonal distance and nodes at that distance
    map<int, vector<int>> m;
    
    // queue for level order traversal
    queue<pair<int, Node*>> q;
    
    q.push({0, root});
    
    // level order
    while(!q.empty()) {
        pair<int, Node*> top = q.front();
        q.pop();
        
        m[top.first].push_back(top.second->data);
        
        if(top.second->left) q.push({top.first-1, top.second->left});
        if(top.second->right) q.push({top.first+1, top.second->right});
    }
    
    // print all the nodes in order
    for(auto it = m.begin(); it != m.end(); it++) {
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << " ";
        }
    }
}
