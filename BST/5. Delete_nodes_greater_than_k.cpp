#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
Node * deleteNode(Node *, int);
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val >= (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        
        int s;
        cin>>s;
        
    Node *R= deleteNode(root,s);
    	inorder(R);
      cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The node structure
struct Node {
int data;
Node * right, * left;
};*/


// To avoid memory leakage
void deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    deleteTree(node->left);  
    deleteTree(node->right);  
      
    /* then delete the node */
    delete node;
} 


/*The function should return the root of the modified tree*/
Node* deleteNode(Node* root, int key) {
    
    // return if the root is NULL
    if(root == NULL) return root;
    
    // check if the node is leaf and its data is less than or greater than equal to key
    if(root->left == NULL && root->right == NULL && root->data < key) return root;

    // if data greater than equal to key, then delete the node and return NULL
    if(root->left == NULL && root->right == NULL && root->data >= key) {
        delete root;
        return NULL;
    }
    
    // if the current root's data is >= key and delete all the nodes to the right of it and return deleteNodes of root's left
    if(root->data >= key) {
        deleteTree(root->right);
        delete root;
        return deleteNode(root->left, key);
    }
    
    // if the current root's data is < key then modify the root's right and return root
    if(root->data < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
}
