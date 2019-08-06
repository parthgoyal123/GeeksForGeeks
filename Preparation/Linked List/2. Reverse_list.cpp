//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}
/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverseList(head);
       printList(head);
       cout << endl;
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Should reverse list and return new head.
Node* reverseList(Node *head) {
    
    // if empty or single element linked list, return head
    if(head == NULL || head->next == NULL) return head;
    
    // use three pointers
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    // reversing done using prev, curr and next
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}