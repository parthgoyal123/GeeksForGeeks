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

int searchInSortedRotated(int *arr, int low, int high, int k) {
    
    // base conditions
    if(low > high) return -1; // not found
    
    int mid = low + (high-low)/2;
    
    if(arr[mid] == k) return mid;
    
    // check if the array is sorted in first half and key lies there or not
    if(arr[low] <= arr[mid]) {
        
        // if key exists in the first half (sorted)
        if(k >= arr[low] && k <= arr[mid]) {
            return searchInSortedRotated(arr, low, mid-1, k);
        } else {
            return searchInSortedRotated(arr, mid+1, high, k);
        }
    } 
    
    // not sorted in first half
    else {
        if(k >= arr[mid] && k <= arr[high]) {
            return searchInSortedRotated(arr, mid+1, high, k);
        } else {
            return searchInSortedRotated(arr, low, mid-1, k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        int k; cin >> k;
        
        cout << searchInSortedRotated(arr, 0, n-1, k) << endl;
    }
}