#include<iostream>
#include<stdio.h>
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
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2) {
    
    // base conditions
    if(!head1 || !head2) return -1;
    
    // get the length of the two linked list
    Node* curr1 = head1;
    Node* curr2 = head2;
    int len1 = 0;
    int len2 = 0;
    
    // length of first
    while(curr1) {
        len1++;
        curr1 = curr1->next;
    }

    // length of second
    while(curr2) {
        len2++;
        curr2 = curr2->next;
    }
    
    curr1 = head1; curr2 = head2;
    
    // if len1 is greater, traverse list 1 ahead
    while(len1 > len2) {
        curr1 = curr1->next;
        len1--;
    }
    
    // if len2 is greater, traverse list 2 ahead
    while(len2 > len1) {
        curr2 = curr2->next;
        len2--;
    }
    
    // now both lists have same length
    while(curr1 && curr2) {
        
        // check if this is the intersection point
        if(curr1 == curr2) {
            return curr1->data;
        }
        
        // if not found yet, traverse both lists ahead
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    return -1;
}