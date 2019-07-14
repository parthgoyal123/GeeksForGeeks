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

void getVerticalOrder(Node* root, int hd, map<int, vector<Node*>> &m) {
    
    if(root == NULL) return;
    
    m[hd].push_back(root);
    
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}
 
void verticalOrder(Node *root) {
    
    if(root == NULL) return;
    
    map<int, vector<Node*>> m;
    
    getVerticalOrder(root, 0, m);
    
    // sort(m.begin(), m.end());
    
    for(auto it = m.begin(); it != m.end(); it++) {
        vector<Node*> vec = it->second;
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i]->data << " ";
        }
    }
}
