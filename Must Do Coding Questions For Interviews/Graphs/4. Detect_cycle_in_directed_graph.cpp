#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicUtil(int v, vector<int> adj[], bool *visited, bool *recStack) {
    
    if(visited[v] == false) { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        vector<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) { 
            if ( !visited[*i] && isCyclicUtil(*i, adj, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
}

bool isCyclic(int V, vector<int> adj[])
{
    // make a bool visited array
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));
    
    // make a bool recursion stack array
    bool *recur = new bool[V];
    memset(recur, false, sizeof(recur));
    
    // traverse for all the nodes
    for(int i = 0; i<V; i++) {
        if(!visited[i]) { // if the current node is not visited so far
            if(isCyclicUtil(i, adj, visited, recur)) {
                return true;
            }
        }
    }
    return false;
    
}