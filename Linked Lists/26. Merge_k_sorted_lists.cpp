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

/*This is a function problem.You only need to complete the function given below*/
/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */


// since we need to build minHeap
struct compareNodes{
    bool operator()(struct Node* a, struct Node* b) {
        return (a->data > b->data);
    }
};

Node * mergeKLists(Node *arr[], int N) {
    
    Node *out = newNode(0);
    Node *tail = out;
    
    priority_queue<Node*, vector<Node*>, compareNodes> pq;
    
    for(int i = 0; i<N; i++) {
        pq.push(arr[i]);
    }
    
    while(!pq.empty()) {
        Node* top = pq.top();
        pq.pop();
        
        int data = top->data;
        tail->next = newNode(data);
        tail = tail->next;
        
        if(top->next) {
            pq.push(top->next);
        }
    }
    
    Node* head = out->next;
    delete out;
    
    return head;
}
