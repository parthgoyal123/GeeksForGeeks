#include <bits/stdc++.h>
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
struct Node *start = NULL;
struct Node* segregate(struct Node *head);
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
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
    
    if(!head  || !head->next) return head;
    
    // make dummy nodes for 0s, 1s, and 2s
    Node *dummy0 = new Node(0);
    Node *dummy1 = new Node(1);
    Node *dummy2 = new Node(2);
    
    Node* zero = dummy0;
    Node* one = dummy1;
    Node* two = dummy2;
    
    Node* curr = head;
    
    while(curr) {
        
        // switch on the data
        switch(curr->data) {
            case 0: {
                zero->next = curr;
                zero = zero->next;
                break;
            }
            
            case 1: {
                one->next = curr;
                one = one->next;
                break;
            }
            
            case 2: {
                two->next = curr;
                two = two->next;
                break;
            }
        }
        
        // traverse curr ahead
        curr = curr->next;
    }
    
    zero->next = (dummy1->next)? dummy1->next: dummy2->next;
    one->next = dummy2->next;
    two->next = NULL;
    
    Node* store = dummy0->next;
    
    delete dummy0, dummy1, dummy2;
    
    return store;
}
