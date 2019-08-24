#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};
//Position this line where user code will be pasted.
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */
// Function to merge two DLLs

Node *sortedMerge(Node* head1, Node* head2) {
    
    // base conditions
    if(!head1) return head2;
    if(!head2) return head1;
    
    // define new_head
    Node* head;
    
    // define the starting point of head
    if(head1->data <= head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }
    
    // store the starting point of head
    Node* store = head;
    
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            head->next = head1;
            head1->prev = head;
            head1 = head1->next;
        } else {
            head->next = head2;
            head2->prev = head;
            head2 = head2->next;
        }
        
        head = head->next;
    }
    
    while(head1) {
        head->next = head1;
        head1->prev = head;
        head1 = head1->next;
        head = head->next;
    }
    
    while(head2) {
        head->next = head2;
        head2->prev = head;
        head2 = head2->next;
        head = head->next;
    }
    
    return store;
}


struct Node *sortDoubly(struct Node *head) {
    
    // base conditions
    if(!head || !head->next) return head;
    
    // find middle element
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* second_half = slow->next;
    second_half->prev = NULL;
    slow->next = NULL;
    
    
    Node* first_half = head;
    
    // sort left and right
    first_half = sortDoubly(first_half);
    second_half = sortDoubly(second_half);
    
    // merge sorted left and right
    head = sortedMerge(first_half, second_half);
    
    return head;
}
