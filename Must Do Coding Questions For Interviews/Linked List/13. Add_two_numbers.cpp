#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* addTwoLists(struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;

}
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

Node* addTwoLists(Node* first, Node* second) {
    
    // make new_head
    Node* new_head = new Node(-1);
    Node* tail = new_head;
    
    Node* cur1 = first;
    Node* cur2 = second;
    
    int carry = 0;
    
    // traverse until same length
    while(cur1 && cur2) {
        tail->next = new Node((cur1->data + cur2->data + carry)%10);
        carry = (cur1->data + cur2->data + carry)/10;
        
        // traverse all pointers ahead
        cur1 = cur1->next;
        cur2 = cur2->next;
        tail = tail->next;
    }
    
    // if length1 > length2
    while(cur1) {
        tail->next = new Node((cur1->data + carry)%10);
        carry = (cur1->data + carry)/10;
        
        tail = tail->next;
        cur1 = cur1->next;
    }
    
    // if length2 > length1
    while(cur2) {
        tail->next = new Node((cur2->data + carry)%10);
        carry = (cur2->data + carry)/10;
        
        tail = tail->next;
        cur2 = cur2->next;
    }
    
    if(carry == 1) {
        tail->next = new Node(1);
        tail = tail->next;
    }
    
    Node* temp = new_head;
    new_head = new_head->next;
    delete temp;
    
    return new_head;
}