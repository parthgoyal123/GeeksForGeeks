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

Node* reverseList(Node *head) {
    if(!head || !head->next) return head;
    
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node *compute(Node *head)
{
    if(!head || !head->next) return head;
    
    head = reverseList(head);
    
    int maximum = head->data;
    Node *curr = head;
    Node* prev = NULL;
    
    while(curr) {
        int data = curr->data;
        
        if(data < maximum) {
            prev->next = curr->next;
            Node* temp = curr;
            delete temp;
            curr = prev->next;
            continue;
        }
        if(data >= maximum) {
            maximum = data;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    head = reverseList(head);
    return head;
    
}