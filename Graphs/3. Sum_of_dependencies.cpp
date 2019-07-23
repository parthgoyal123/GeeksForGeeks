#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int getDependenciesSum(vector<int> *adj, int n) {
    int count = 0;
    loop(i,0,n) {
        iterate(it, adj[i]) {
            count++;
        }
    }
    
    // adj[0].push_back(10000000);
    
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        
        vector<int> adj[n];
        
        int from, to;
        loop(i,0,e) {
            cin >> from >> to;
            adj[from].pb(to);
        }
        // iterate(it, adj[0]) {
        //     cout << *it << " ";
        // } cout << endl;
        cout << getDependenciesSum(adj, n) << endl;
        // iterate(it, adj[0]) {
        //     cout << *it << " ";
        // } cout << endl;
    }
}