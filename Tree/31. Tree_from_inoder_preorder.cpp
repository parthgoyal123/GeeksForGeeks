#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

Node* buildTreeUtil(int *in, int *pre, int start, int end, int &index) {
    if(start>end) return NULL;
    
    Node* root = newNode(pre[index]);
    index++;
    
    if(start == end) return root;
    
    int i;
    for(i = start; i<=end; i++) {
        if(in[i] == root->data) break;
    }
    
    root->left = buildTreeUtil(in, pre, start, i-1, index);
    root->right = buildTreeUtil(in, pre, i+1, end, index);
    
    return root;
}

Node* buildTree(int *in, int *pre, int start, int end) {
    int index = 0;
    return buildTreeUtil(in, pre, start, end, index);
}