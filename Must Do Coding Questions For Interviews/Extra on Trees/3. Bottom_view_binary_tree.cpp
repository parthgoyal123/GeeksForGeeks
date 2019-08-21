// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
// Method that prints the bottom view.
void bottomView(Node *root){
    // base check
    if(root == NULL) return;
    
    // map that stores Nodes as per horizontal distances
    map<int, Node*> m;
    
    // queue for level order traversal
    // pair<int, Node*> int: horizontal distance
    queue<pair<int, Node*>> q;
    
    // store max and min horizontal distance
    int min_hd = INT_MAX, max_hd = INT_MIN;
    
    q.push({0, root});
    
    while(!q.empty()) {
        
        // get current size
        int curr_size = q.size();
        
        while(curr_size--) {
            
            // get the top element
            pair<int, Node*> top = q.front();
            q.pop();
            
            // store current node at this horizontal distance
            m[top.first] = top.second;
            
            // update min_hd and max_hd
            min_hd = min(min_hd, top.first);
            max_hd = max(max_hd, top.first);
            
            // push left and right to queue along with their appropiate horizontal distances
            if(top.second->left) q.push({top.first-1, top.second->left});
            if(top.second->right) q.push({top.first+1, top.second->right});
        }
    }
    
    for(int i = min_hd; i <= max_hd; i++) {
        cout << m[i]->data << " ";
    }
}