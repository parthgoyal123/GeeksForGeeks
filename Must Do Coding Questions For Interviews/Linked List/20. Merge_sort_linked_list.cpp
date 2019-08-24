#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
//Position this line where user code will be pasted.
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */
   
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
            head1 = head1->next;
        } else {
            head->next = head2;
            head2 = head2->next;
        }
        
        head = head->next;
    }
    
    while(head1) {
        head->next = head1;
        head1 = head1->next;
        head = head->next;
    }
    
    while(head2) {
        head->next = head2;
        head2 = head2->next;
        head = head->next;
    }
    
    return store;
}
   
   
Node* mergeSort(Node* head) {
    
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
    slow->next = NULL;
    
    Node* first_half = head;
    
    // sort left and right
    first_half = mergeSort(first_half);
    second_half = mergeSort(second_half);
    
    // merge sorted left and right
    head = sortedMerge(first_half, second_half);
    
    return head;
}
