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

typedef pair<int, Node*> pin;

void bottomView(Node *root)
{
    // base conditions
    if(!root) return;
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }

    // use queue and pair<int, Node*> --> horizontal_distance(hd), Node*
    queue<pin> q;
    
    q.push({0, root});
    
    map<int, Node*> m;
    
    // do level order traversal
    while(!q.empty()) {
        
        // extract top Node
        pin top = q.front();
        q.pop();
        
        // put the node at horizontal distance
        m[top.first] = top.second;
        
        // push left and right nodes in queue
        if(top.second->left) q.push({top.first-1, top.second->left});
        if(top.second->right) q.push({top.first+1, top.second->right});
    }
    
    // print all nodes at all horizonal distances in increasing order
    for(auto it = m.begin(); it!= m.end(); it++) {
        cout << it->second->data << " ";
    }
}