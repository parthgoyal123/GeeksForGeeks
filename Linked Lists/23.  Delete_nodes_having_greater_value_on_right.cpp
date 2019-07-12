#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node *compute(Node *head);
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}


/*This is a function problem.You only need to complete the function given below*/
/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/

void deleteNode(Node* node) {
    if(node == NULL) return;
    if(node->next == NULL) {
        delete node;
        return;
    }
    
    node->data = node->next->data;
    Node* temp = node->next;
    node->next = temp->next;
    delete(temp);
}

Node *compute(Node *head){
    if(!head || !head->next) return head;
    
    stack<Node*> s;
    Node* curr = head;
    s.push(curr);
    
    while(curr) {
        curr = curr->next;
        int data = curr->data;
        
        while(!s.empty() && data > s.top()->data) {
            Node* top = s.top();
            s.pop();
            deleteNode(top);
        }
        s.push(curr);
    }
    
    return head;
}