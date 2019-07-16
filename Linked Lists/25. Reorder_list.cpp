#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
 void reorderList(struct Node* head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=newNode(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=newNode(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
freeList(head);
   }
   return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/

Node* reverseList(Node* root) {
    if(root == NULL || root->next == NULL) return root;
    
    Node* prev = NULL;
    Node* curr = root;
    Node* next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node* mergeAlternatively(Node* first, Node* second) {
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    Node* head = newNode(0);
    Node* tail = head;
    
    while(first!= NULL && second != NULL) {
        tail->next = first;
        first = first->next;
        tail = tail->next;
        tail->next = second;
        second = second->next;
        tail = tail->next;
    }
    
    while(first) {
        tail->next = first;
        first = first->next;
        tail = tail->next;
    }
    
    if(tail != NULL) tail->next = NULL;
    
    return head->next;
}

void reorderList(Node* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return;
    
    Node* slow = head;
    Node* fast = head;
    Node* first_half = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* second_half = slow->next;
    slow->next = NULL;
    
    second_half = reverseList(second_half);
    
    head = mergeAlternatively(first_half, second_half);
}