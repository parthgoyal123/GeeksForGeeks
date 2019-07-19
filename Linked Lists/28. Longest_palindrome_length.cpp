// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);
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
      
       cout << maxPalindrome(head)<<endl;
    }
    return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/* The Node is defined 
  struct Node
  {
     int data;
     Node *next;
  } */
/*The function below returns an int denoting
the length of the longest palindrome list. */

int maxPalindromeUtil(Node* a, Node* b) {
    int count = 0;
    
    for(; a && b; a = a->next, b = b->next) {
        if(a->data == b->data) {
            count++;
        } else {
            break;
        }
    }
    
    return count;
}

Node* reverseList(Node* head) {
    if(!head || !head->next) return head;
    
    Node* curr = head, *prev = NULL, *next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int maxPalindrome(Node *head) {
    if(!head) return 0;
    if(!head->next) return 1;
    
    Node* curr = head, *prev = NULL, *next = NULL;
    int max_length = 1;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        
        int odd_length = 2*maxPalindromeUtil(prev, next) + 1;
        int even_length = 2*maxPalindromeUtil(curr, next);
        
        max_length = max(max_length, max(odd_length, even_length));
        prev = curr;
        curr = next;
    }
    
    head = reverseList(head);
    
    return max_length;
}