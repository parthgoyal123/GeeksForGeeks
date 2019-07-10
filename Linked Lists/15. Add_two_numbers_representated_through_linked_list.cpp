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
    printf("\n");
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
// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    Node *root = NULL;
    Node *tail = NULL;
    
    if(!first && !second) return NULL;
    
    if(!first) return second;
    if(!second) return first;
    
    int carry = 0;
    
    while(first != NULL && second != NULL) {
        int sum = first->data + second->data + carry;
        if(sum < 10) carry = 0;
        
        if(sum >= 10) {
            sum = sum%10;
            carry = 1;
        } 
        if(root == NULL) {
            root = new Node (sum);
            tail = root;
        } else {
            tail->next = new Node(sum);
            tail = tail->next;
        }
        
        first = first->next;
        second = second->next;
    }
    
    Node* curr = (first == NULL)? second: first;
    
    while(curr != NULL) {
        int sum = curr->data + carry;
        if(sum < 10) carry = 0;
        
        if(sum >= 10) {
            sum = sum%10;
            carry = 1;
        } 
        if(root == NULL) {
            root = new Node (sum);
            tail = root;
        } else {
            tail->next = new Node(sum);
            tail = tail->next;
        }
        
        curr = curr->next;
    }
    if(carry == 1) tail->next = new Node(1);
    
    return root;
}