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

void sortArray(int *arr, int n, int k) {
    
    // if k == n, then its a normal array to be sorted
    if(k == n) {
        sort(arr, arr+n);
        return;
    }
    
    // make priority queue of size k
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k+1);
    
    int ind = 0;
    
    // insert first k elements
    for(int i = k+1; i<n; i++) {
        arr[ind++] = pq.top();
        pq.pop();
        
        pq.push(arr[i]);
    }
    
    // empty the queue
    while(!pq.empty()) {
        arr[ind++] = pq.top();
        pq.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        sortArray(arr, n, k);
        printArray(arr, n);
    }
}