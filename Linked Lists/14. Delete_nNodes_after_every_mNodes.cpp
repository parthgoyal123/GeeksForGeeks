{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */
void linkdelete(struct node  *head, int M, int N);
struct node
{
    int data;
    struct node *next;
};
    struct node *start = NULL;
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
    
}
void insert(int n1)
{
    int n,value;
    n=n1;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start=(struct node *) malloc( sizeof(struct node) );
            start->data=value;
            start->next=NULL;
            temp=start;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
    cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
 insert(n1);
        linkdelete(start,m,n);
    printList(start);
    }
    
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/

#define loop(i, a, b) for(int i = a; i<b; i++)

void linkdelete(struct node  *head, int m, int n)
{
    node *temp = head;
    
    while(temp != NULL) {
        loop(i, 0, m-1) {
            if(temp != NULL)
                temp = temp->next;
            else return;
        }
        if(temp == NULL) return;
        
        loop(i, 0, n) {
            node *temp2 = temp->next;
            if(temp2 == NULL) return;
            temp->next = temp2->next;
            delete temp2;
        }
        
        temp = temp->next;
    }
}