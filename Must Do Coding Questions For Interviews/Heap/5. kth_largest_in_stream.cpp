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
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

vector<int> getKthLargest(int *arr, int n, int k) {
    
    // make vector to store result
    vector<int> result;
    
    // lets make a priority queue of size k (min Heap)
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i<n; i++) {
        
        // if size of queue if less than k-1 and simply push to array
        if(pq.size() < k-1) {
            pq.push(arr[i]);
            result.pb(-1);
            continue;
        }
        
        // if only one element is less in pq
        if(pq.size() == k-1) {
            pq.push(arr[i]);
            
            result.pb(pq.top());
            continue;
        }
        
        // now what if pq is full ?
        
        // if top is less than new element, top becomes (k+1)th largest
        if(pq.top() < arr[i]) {
            
            // pop previous top and push new element
            pq.pop();
            pq.push(arr[i]);
        }
        
        result.pb(pq.top());
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> k >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        vector<int> kthLargest = getKthLargest(arr, n, k);
        
        iterate(it, kthLargest) {
            cout << *it << " ";
        } cout << endl;
    }
}