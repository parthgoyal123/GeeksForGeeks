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

void getMaximumOfAllSubarray(int *arr, int n, int k) {
    
    // make a deque that stores element in decreasing order from front to back
    deque<int> dq(k);
    
    // index of array
    int i = 0;
    
    // make dq for first k elements
    for(i = 0; i<k; i++) {
        
        // pop out all smaller elements from back
        while(!dq.empty() && (arr[dq.back()] <= arr[i])) dq.pop_back();
        
        // push back the new element index;
        dq.push_back(i);
    }
        
    // print max of previous window
    cout << arr[dq.front()] << " ";
    
    // get max for all rest elements
    for(; i<n; i++) {
        
        // pop all the elements that are now out of window
        while(!dq.empty() && (dq.front() <= i-k)) dq.pop_front();
        
        // pop out all smaller elements from back
        while(!dq.empty() && (arr[dq.back()] <= arr[i])) dq.pop_back();
        
        // push back the new element index;
        dq.push_back(i);
        
        cout << arr[dq.front()] << " ";
    }
    
    cout << endl;
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
        
        getMaximumOfAllSubarray(arr, n, k);
    }
}