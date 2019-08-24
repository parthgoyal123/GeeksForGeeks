#include <bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};
using namespace std;
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node* flatten (Node* root);
int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}


// merge two lists with only bottom nodes
Node* merge(Node* head1, Node* head2) {
    
    // base conditions
    if(!head1) return head2;
    if(!head2) return head1;
    
    // define new_head
    Node* head;
    
    // define the starting point of head
    if(head1->data <= head2->data) {
        head = head1;
        head1 = head1->bottom;
    } else {
        head = head2;
        head2 = head2->bottom;
    }
    
    // store the starting point of head
    Node* store = head;
    
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            head->bottom = head1;
            head1 = head1->bottom;
        } else {
            head->bottom = head2;
            head2 = head2->bottom;
        }
        
        head = head->bottom;
    }
    
    while(head1) {
        head->bottom = head1;
        head1 = head1->bottom;
        head = head->bottom;
    }
    
    while(head2) {
        head->bottom = head2;
        head2 = head2->bottom;
        head = head->bottom;
    }
    
    return store;
}
    

// the flattened linked list should be vertical (should only have bottom nodes) in non-decreasing order    
Node *flatten(Node *root) {
    
    // if no right or no node, return root
    if(!root || !root->next) return root;
    
    // return merged of root and flattened root->next
    return merge(root, flatten(root->next));
}