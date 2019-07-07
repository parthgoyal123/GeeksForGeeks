#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct node* findIntersection(struct node* head1, struct node* head2);
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* findIntersection(struct node* head1, struct node* head2)
{
    map<int, int, greater<int>> hash;
    if(head1 == NULL || head2 == NULL) return NULL;
    
    while(head1 != NULL) {
        hash[head1->data] = 1;
        head1 = head1->next;
    }
    
    while(head2 != NULL) {
        if(hash.find(head2->data) != hash.end()) {
            hash[head2->data] = 2;
        }
        head2 = head2->next;
    }
    
    set<int, greater<int>> intersect;
    for(auto it = hash.begin(); it!= hash.end(); it++){
        if(it->second == 2) {
            intersect.insert(it->first);
        }
    }
    
    node* head = NULL;
    for(auto it = intersect.begin(); it!= intersect.end(); it++) {
        push(&head, *it);
    }
    return head;
}