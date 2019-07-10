#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
;}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/


int maxPathSumUtil(Node* root, int& max_sum) {
    
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    
    int left_sum = maxPathSumUtil(root->left, max_sum);
    int right_sum = maxPathSumUtil(root->right, max_sum);
    
    if(root->left && root->right) {
        max_sum = max(max_sum, left_sum + right_sum + root->data);
        
        return max(left_sum, right_sum) + root->data;
    }
    if(!root->left) return right_sum + root->data;
    else return left_sum + root->data;
}

int maxPathSum(struct Node *root)
{
    int max_sum = INT_MIN;
    maxPathSumUtil(root, max_sum);
    
    return max_sum;
}