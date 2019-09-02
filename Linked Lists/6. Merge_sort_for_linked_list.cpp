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
    printf("\n");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
Node* mergeSort(Node* head);
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

Node* sortedMerge(Node* head1, Node *head2) {
    if(head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    }

    // get the head of the merged lists
    Node* head;
    if ((head1->data) <= (head2->data)) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    Node* store = head;

    // iterate till none is NULL
    while(head1 != NULL && head2 != NULL) {
        if ((head1->data) <= (head2->data)) {
            head->next = head1;
            head1 = head1->next;
        } else {
            head->next = head2;
            head2 = head2->next;
        }
        head = head->next;
    }

    while(head1 != NULL) {
        head->next = head1;
        head1 = head1->next;
        head = head->next;
    }

    while(head2 != NULL) {
        head->next = head2;
        head2 = head2->next;
        head = head->next;
    }

    return store;
}


Node* mergeSort(Node* head) {
    
    // if 0 or 1 node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // get the breaking middle point using slow and fast pointers
    Node* slow = head;  
    Node* fast = head->next;
    
    // store the head pointer 
    Node* first_half = head;
    
    while(fast!= NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // get the starting point of the second half of the linked list
    Node* second_half = slow->next;
    
    // terminate the list after the middle node
    slow->next = NULL;
    
    // sort the first and second half
    first_half = mergeSort(first_half);
    second_half = mergeSort(second_half);
    
    // merge the sorted first and second half
    return sortedMerge(first_half, second_half);
}