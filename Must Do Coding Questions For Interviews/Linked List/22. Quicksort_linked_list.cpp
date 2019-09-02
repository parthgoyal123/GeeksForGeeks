#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 node* newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = newNode(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=newNode(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}


/* get tail node of linked list */
struct node* getTailNode(struct node **headRef) {
    struct node *curr = *headRef;
    while(curr && curr->next) curr = curr->next;
    return curr;
}

/* partition the list */
struct node* partition(struct node* head, struct node* end, struct node **newHead, struct node **newEnd) {
    
    struct node* pivot = end;
    struct node* prev = NULL, *curr = head, *tail = pivot;
    
    while(curr != pivot) {
        
        // if the node has smaller value than pivot
        if(curr->data < pivot->data) {
            
            // if this is the first element that is smaller than the pivot
            if((*newHead) == NULL) *newHead = curr;
            
            // traverse ahead
            prev = curr;
            curr = curr->next;
        } else {
            
            // move the current node to the end of tail
            if(prev) prev->next = curr->next;
            
            struct node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            
            curr = temp;
        }
    }
    
    // if the pivot is the smallest element in the list
    if((*newHead) == NULL) *newHead = pivot;
    
    // update newEnd to the current tail node
    (*newEnd) = tail;
    
    return pivot;
}

/* quicksort recursive fashion (here sorting happens exclusive of the end node */
struct node* quickSortRecur(struct node* head, struct node* end) {
    
    // base condition 
    if (!head || head == end) 
        return head; 
  
    struct node *newHead = NULL, *newEnd = NULL; 
  
    // Partition the list, newHead and newEnd will be updated 
    // by the partition function 
    struct node *pivot = partition(head, end, &newHead, &newEnd);
    
    // if pivot is the smallest element, no need to recur for the left part
    if(newHead != pivot) {
        
        // Set the node before the pivot node as NULL 
        struct node *tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = NULL; 
  
        // Recur for the list before pivot 
        newHead = quickSortRecur(newHead, tmp); 
  
        // Change next of last node of the left half to pivot 
        tmp = getTailNode(&newHead); 
        tmp->next =  pivot;
    }
    
    // recur for the right part
    pivot->next = quickSortRecur(pivot->next, newEnd);
    
    return newHead;
}

/* call made for quicksort */
void quickSort(struct node **headRef) {
    struct node *tail = getTailNode(headRef);
    (*headRef) = quickSortRecur(*headRef, tail);
}