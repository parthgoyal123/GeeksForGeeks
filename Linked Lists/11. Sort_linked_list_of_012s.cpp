#include <stdio.h>
#include <stdlib.h>
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node *start = NULL;
struct Node* segregate(struct Node *head);
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}
int main() {
    int n;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     Node *next;
  }
*/
// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);
    
    Node* zero = zeroD;
    Node* one = oneD;
    Node* two = twoD;
    
    Node* curr = head;
    
    while(curr != NULL) {
        if(curr->data == 1) {
            one->next = curr;
            one = one->next;
            curr = curr->next;
        } else if (curr->data == 2) {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        } else {
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }
    }
    
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;
    
    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;
    
    return head;
}