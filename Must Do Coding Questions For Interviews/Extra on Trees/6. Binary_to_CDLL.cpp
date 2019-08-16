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
Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}
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
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void bToDLL(Node *root, Node **head_ref){
    
    // check for valid root
    if(root == NULL) return;
    
    // make right subtree DLL
    bToDLL(root->right, head_ref);
    
    // change the right pointer to point to head pointer
    root->right = *head_ref;
    
    // point the head_ref's left to root, if head_ref is not NULL
    if(*head_ref != NULL) {
        (*head_ref)->left = root;
    }
    
    // change the head_pointer location
    *head_ref = root;
    
    // now make left subtree to DLL
    bToDLL(root->left, head_ref);
}

Node* bTreeToCList(Node* root) {
    Node *head_ref = NULL;
    
    // first convert binary tree to DLL
    bToDLL(root, &head_ref);
    
    Node *start = head_ref;
    Node *curr = head_ref;
    Node* prev;

    if(head_ref) {
        while(curr) {
            prev = curr;
            // cout << curr->data << " ";
            curr = curr->right;
        }
        
        // cout << endl;
        
        // attach start and last node
        start->left = prev;
        prev->right = start;

        return start;
    }

    return head_ref;
}