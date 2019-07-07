#include<bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}
struct Node * mergeResult(struct Node *node1,struct Node *node2);
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;
        struct Node* headA=NULL;
        struct Node* tempA = headA;
        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);
            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }
        struct Node* headB=NULL;
        struct Node* tempB = headB;
        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);
            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        struct Node* result = mergeResult(headA,headB);
        print(result);
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
struct Node * mergeResult(Node *node1,Node *node2)
{
    if(node1==NULL) return node2;
    if(node2==NULL) return node1;
    
    Node* head = NULL;
    
    if((node1->data) <= (node2->data)) {
        head = node1;
        node1 = node1->next;
        head->next = NULL;
    } else {
        head = node2;
        node2 = node2->next;
        head->next = NULL;
    }
    
    Node* temp;
    while(node1 != NULL && node2 != NULL) {
        if((node1->data) <= (node2->data)) {
            temp = node1->next;
            node1->next = head;
            head = node1;
            node1 = temp;
        } else {
            temp = node2->next;
            node2->next = head;
            head = node2;
            node2 = temp;
        }
    }
    
    while(node1 != NULL) {
        temp = node1->next;
        node1->next = head;
        head = node1;
        node1 = temp;
    }
    
    while(node2 != NULL) {
        temp = node2->next;
        node2->next = head;
        head = node2;
        node2 = temp;
    }
    
    return head;
}