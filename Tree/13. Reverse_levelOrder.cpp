#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void reversePrint(Node *root);
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
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
   reversePrint(root);
   cout<<endl;
  }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void printReverse(queue<Node*> &q) {
    if(q.empty()) return;
    
    Node* top = q.front();
    q.pop();
    if(top->right != NULL) q.push(top->right);
    if(top->left != NULL) q.push(top->left);
    printReverse(q);
    
    cout << top->data << " ";
}


void reversePrint(Node *root)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        cout << root->data; return;
    }
    
    queue<Node*> q;
    q.push(root);
    printReverse(q);
}