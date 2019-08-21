#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int longestConsecutive(Node* root);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<longestConsecutive(root)<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
struct Node
{
	int data;
	Node *left, *right;
};
*/

void longestConsecutiveUtil(Node *root, int &maxx, int prev_data, int length_till_now) {
    
    // base case
    if(root == NULL) return;
    
    // if the current data is in increasing order to previous
    if(root->data == prev_data + 1) {
        
        // change current_data
        length_till_now += 1;
        
        // change maxx length
        maxx = max(maxx, length_till_now);
        
        // change the prev_data
        prev_data = root->data;
    } 
    
    // if this is not in increasing sense, start from 1
    else {
        length_till_now = 1;
        maxx = max(maxx, length_till_now);
        prev_data = root->data;
    }
    
    longestConsecutiveUtil(root->left, maxx, prev_data, length_till_now);
    longestConsecutiveUtil(root->right, maxx, prev_data, length_till_now);
}


// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence
int longestConsecutive(Node* root)
{
    // max length
    int maxx = 0;
    
    // recur for left and right
    longestConsecutiveUtil(root, maxx, INT_MIN, INT_MIN);
    
    if(maxx == 1) return -1;
    else return maxx;
    
}