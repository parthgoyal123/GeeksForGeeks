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
void printSpiral(Node *root)
{
    queue<Node*> q;
    
    q.push(root);
    
    bool flag = false;
    while(!q.empty()) {
        
        int curr_size = q.size();
        
        stack<Node*> s;
        
        while(curr_size--) {
            Node* top = q.front();
            q.pop();
            if(!flag) s.push(top);
            else cout << top->data << " ";
            
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
        }
        
        while(!s.empty()) {
            Node* top = s.top();
            s.pop();
            cout << top->data << " ";
        }
        flag = !flag;
    }
}