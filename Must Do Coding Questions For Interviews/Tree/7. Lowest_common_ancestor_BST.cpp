//Code by 1shubhamjoshi1
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
Node* LCA(Node *root, int , int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int l,r;
        cin>>l>>r;
        cout<<LCA(root,l,r)->data<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2) {

    // base condition
    if(!root) return root;
   
    // check for root's data
    if(root->data == n1 || root->data == n2) return root;
    
    // if one node in left subtree and other in right subtree
    if((root->data < n1 && root->data > n2) || (root->data < n2 && root->data > n1)) return root;
    
    // if root data is bigger than both value
    if(root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);

    // if root data is smaller than both values
    if(root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
}
