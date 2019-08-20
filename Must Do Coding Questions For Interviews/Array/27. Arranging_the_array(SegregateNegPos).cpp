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

void merge(ll int *arr, int low, int mid, int high) {
    
    // define the size of arrays to be merged
    int n1 = mid-low+1;
    int n2 = high-mid;
    
    ll int L[n1], R[n2];
    
    for(int i = 0; i<n1; i++) {
        L[i] = arr[low+i];
    }
    
    for(int i = 0; i<n2; i++) {
        R[i] = arr[i+mid+1];
    }
    
    int i = 0;
    int j = 0;
    int k = low;
    
    // first put -ve elements of first subarray
    while(i < n1 && L[i] < 0) {
        arr[k++] = L[i++];
    }
    
    // put -ve elements of second subarray
    while(j < n2 && R[j] < 0) {
        arr[k++] = R[j++];
    }
    
    // secondly put +ve elements of first subarray
    while(i < n1 && L[i] >= 0) {
        arr[k++] = L[i++];
    }
    
    // put +ve elements of second subarray
    while(j < n2 && R[j] >= 0) {
        arr[k++] = R[j++];
    }
}

void segregateNegAndPos(ll int *arr, int low, int high) {
    
    // approach similar to mergesort
    if(low < high) {
        int mid = low + (high-low)/2;
        
        segregateNegAndPos(arr, low, mid);
        segregateNegAndPos(arr, mid+1, high);
        
        // this merge function is different
        merge(arr, low, mid, high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        segregateNegAndPos(arr, 0, n-1);
        printArray(arr, n);
    }
}