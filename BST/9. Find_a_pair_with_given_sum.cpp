#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
struct node
{
    int val;
    struct node *left, *right;
};
bool isPairPresent(struct node *root, int target);
struct node * Newnode(int val)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->right = tmp->left =NULL;
    return tmp;
}
struct node *insert(struct node *root,int a){
	if(root==NULL)
		return Newnode(a);
	if(root->val>a){
		root->left=insert(root->left,a);
	}
	if(root->val<a){
		root->right=insert(root->right,a);
	}
	return root;
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,target;
		cin>>n>>target;
		struct node *root =  NULL;
		while(n--){
			int a;
			cin>>a;
			if(root==NULL){
				root=Newnode(a);
			}
			else{
				insert(root,a);
			}
		}
		//inorder(root);
    cout<<isPairPresent(root, target)<<endl;
	}
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
bool isPairPresent(struct node *root, int target) {
    
    if(!root || (!root->left && !root->right)) return false;
    
    stack<node*> s1;
    stack<node*> s2;
    
    node* curr1 = root;
    node* curr2 = root;
    
    bool flag1 = false;
    bool flag2 = false;
    
    int val1, val2;
    
    while(1) {
        
        while(flag1 == false) {
            if(curr1 != NULL) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if(s1.empty()) {
                    flag1 = true;
                } else {
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->val;
                    curr1 = curr1->right;
                    flag1 = true;
                }
            }
        }
        
        
        while(flag2 == false) {
            if(curr2 != NULL) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if(s2.empty()) flag2 = true;
                else {
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->val;
                    curr2 = curr2->left;
                    flag2 = true;
                }
            }
        }
        
        if(val1 != val2 && val1 + val2 == target) return true;
        
        if(val1 + val2 > target) flag2 = false;
        if(val1 + val2 < target) flag1 = false;
        
        
        if(val1 >= val2) return false;
    }
}