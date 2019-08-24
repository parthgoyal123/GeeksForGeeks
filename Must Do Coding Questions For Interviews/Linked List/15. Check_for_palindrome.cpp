#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
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
/*You are required to complete this method */
bool isPalindrome(Node *head) {
    
    if(!head || !head->next) return 1;
    
    // store half elements in stack and pop after half
    stack<int> st;
    
    Node* slow = head;
    st.push(slow->data);
    Node* fast = head->next;
    
    while(fast && fast->next) {
        slow = slow->next;
        st.push(slow->data);
        fast = fast->next->next;
    }
    
    // slow is the middle node now
    if(fast == NULL) st.pop();
    
    Node* after = slow->next;
    while(!st.empty() && after) {
        if(st.top() != after->data) return false;
        
        st.pop();
        after = after->next;
    }
    
    return (st.empty() && after == NULL);
}
