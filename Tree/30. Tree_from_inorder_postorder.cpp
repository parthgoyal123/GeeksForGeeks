/* program to construct tree using inorder and postorder traversals */
#include<bits/stdc++.h>
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
/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}
Node *buildTree(int in[], int post[], int n);
int main()
{
	int t,n;
	cin>>t;
	int in[1000], post[1000];
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
		cout<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure
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
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

Node *buildTreeUtil(int* in, int* post, int start, int end, int &pIndex) {
    if(start > end) return NULL;
    if(start == end) return new Node(post[pIndex--]);
    
    // cout << "pIndex : " << pIndex << endl;
    Node* root = new Node(post[pIndex]);
    pIndex--;
    
    int data = root->data;
    int i;
    
    for(i = start; i <= end; i++) {
        if(in[i] == data) {
            break;
        }
    }
    
    // cout << "root i : " << i << endl;
    
    root->right = buildTreeUtil(in, post, i+1, end, pIndex);
    // if(root->right) cout << "root->right->data : " << root->right->data << endl;
    
    root->left = buildTreeUtil(in, post, start, i-1, pIndex);
    // if(root->left) cout << "root->left->data : " << root->left->data << endl;
    
    return root;
}

Node *buildTree(int *in, int *post, int n) {
    int pIndex = n-1;
    
    return buildTreeUtil(in, post, 0, n-1, pIndex);
}
