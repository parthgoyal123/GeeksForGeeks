#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node *rotate(struct Node *head, int k);
Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
/* Drier program to test above function*/
int main(void) {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
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
}; */
/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    
    // base conditions
    if(!head || !head->next || k == 0) return head;
    
    // traverse k steps ahead
    Node* curr = head;
    int count = 1;
    
    while(count < k && curr != NULL) {
        count += 1;
        curr = curr->next;
    }
    
    // check if k is greater than or equal to length of linked list
    if(count < k || curr == NULL) return head;
    
    // store the kth Node
    Node* store = curr;
    
    // get to the last of the linked list
    while(curr->next) curr = curr->next;
    
    // assign last to start
    curr->next = head;
    
    // assign the new head
    head = store->next;
    
    store->next = NULL;
    
    return head;
}
