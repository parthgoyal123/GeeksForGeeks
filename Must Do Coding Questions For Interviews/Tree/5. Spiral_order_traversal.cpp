#include<bits/stdc++.h>
using namespace std;
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
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printSpiral(root);
    cout<<endl;
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
}; */
void printSpiral(Node *root) {
    
    // base conditions
    if(!root) return;
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    
    // use level order and also a stack
    queue<Node*> q;
    stack<int> s;
    
    q.push(root);
    
    int count = 1;
    
    // perform level order traversal
    while(!q.empty()) {
        int curr_size = q.size();
        
        while(curr_size--) {
            Node* top = q.front();
            q.pop();
            
            // print only in case when count is even
            if(count%2 == 0) cout << top->data << " ";
            
            // push in stack in case when count in odd
            if(count%2 == 1) s.push(top->data);
            
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            
        }
        
        if(count%2 == 1) {
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        
        count++;
    }
}
