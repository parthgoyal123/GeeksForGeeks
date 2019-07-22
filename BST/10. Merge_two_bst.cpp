
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
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
void inorder(Node* root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);} 
       merge(root1,root2); cout << endl;
       inorder(root1); cout << endl;
       inorder(root2); cout << endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/

/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/
/*You are required to complete below method */

void inorder(Node* root) {
    if(!root) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void merge(Node *root1, Node *root2) {
    if(!root1 && !root2) return;
    
    if(!root1) {
        inorder(root2);
        return;
    }
    
    if(!root2) {
        inorder(root1);
        return;
    }
    
    stack<Node*> s1;
    stack<Node*> s2;
    
    Node* curr1 = root1;
    Node* curr2 = root2;
    
    while(curr1 != NULL || curr2 != NULL || !s1.empty() || !s2.empty()) {
        if(curr1 != NULL || curr2 != NULL) {
            if(curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            
            if(curr2) {
                s2.push(curr2);
                curr2 = curr2->left;
            }
        } else {
            if(s1.empty()) {
                while(!s2.empty()) {
                    Node* t2 = s2.top();
                    s2.pop();
                    
                    Node* store = t2->left;
                    t2->left = NULL;
                    
                    inorder(t2);
                    
                    t2->left = store;
                }
                
            }
            
            else if (s2.empty()) {
                while(!s1.empty()) {
                    Node* t1 = s1.top();
                    s1.pop();
                    
                    Node* store = t1->left;
                    t1->left = NULL;
                    
                    inorder(t1);
                    
                    t1->left = store;
                }
            } 
            
            else {
                Node* t1 = s1.top();
                Node* t2 = s2.top();
                
                if(t1->data == t2->data) {
                    cout << t1->data << " " << t2->data << " ";
                    s1.pop();
                    s2.pop();
                    curr1 = t1->right;
                    curr2 = t2->right;
                    
                } else if (t1->data < t2->data) {
                    s1.pop();
                    cout << t1->data << " ";
                    curr1 = t1->right;
                } else {
                    s2.pop();
                    cout << t2->data << " ";
                    curr2 = t2->right;
                }
            }
        }
    }
}