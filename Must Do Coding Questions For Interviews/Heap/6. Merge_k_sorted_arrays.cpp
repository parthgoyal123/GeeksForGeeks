// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;
// A Linked List node
struct Node
{
	int data;
	Node* next;
};
Node* mergeKLists(Node* arr[], int N);
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
// Utility function to create a new node.
Node *newNode(int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;
           int x;
           cin>>x;
           arr[j]=newNode(x);
           Node *curr = arr[j];
           n--;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = newNode(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Node *res = mergeKLists(arr,N);
		printList(res);
   }
	return 0;
}


/* make a comparator function that compares two Nodes*/

struct compare {
    bool operator()(struct Node *a, struct Node *b) {
        return a->data > b->data;
    }
};


/* arr[] is an array of pointers to heads of linked lists and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N) {
    
    // make a dummy head(it's next is to be returned) ;
    Node* head = newNode(0);
    Node* tail = head;
    
    // make prioriy queue of size N
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    for(int i = 0; i<N; i++) {
        pq.push(arr[i]);
    }
    
    // traverse through the pq
    while(!pq.empty()) {
        Node* top = pq.top();
        pq.pop();
        
        if(top->next) pq.push(top->next);
        
        tail->next = top;
        tail = tail->next;
    }
    
    // head should have a next if valid input
    if(head->next) {
        Node* temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }
    
    return NULL;
}