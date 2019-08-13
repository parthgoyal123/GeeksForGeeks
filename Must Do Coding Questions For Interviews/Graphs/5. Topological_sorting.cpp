#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/

void topologicalSortUtil(int v, vector<int> adj[], bool *visited, stack<int> &Stack) {
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    vector<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, adj, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v);
}

int* topoSort(int V, vector<int> adj[])
{
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, adj, visited, Stack); 
    
    int *arr = new int[V];
    
    // fill the topologically sorted stack to array
    int i = 0;
    while(!Stack.empty()) {
        arr[i++] = Stack.top();
        Stack.pop();
    }
    
    return arr;
}
