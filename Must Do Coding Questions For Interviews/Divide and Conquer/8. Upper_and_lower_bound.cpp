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

int firstOccurence(ll int *arr, int low, int high, int k) {
    
    // base condition
    if(low > high) return -1;
    
    int mid = low + (high-low)/2;
    
    // check if this matches but not previous
    if(arr[mid] == k && arr[mid-1] != k) return mid;
    
    // if previous also matches, check for first occurence in left subarray
    if(arr[mid] == k && arr[mid-1] == k) {
        return firstOccurence(arr, low, mid-1, k);
    }
    
    // basic binary search
    if(arr[mid] < k) {
        return firstOccurence(arr, mid+1, high, k);
    } else {
        return firstOccurence(arr, low, mid-1, k);
    }
}

int lastOccurence(ll int *arr, int low, int high, int k) {
    
    // base condition
    if(low > high) return -1;
    
    int mid = low + (high-low)/2;
    
    // cout << low << " " << mid << " " << high << endl;
    
    // if it the last index 
    if(arr[mid] == k && arr[mid+1] != k) return mid;
    
    // if next element is also k, then recur for right subarray
    if(arr[mid] == k && arr[mid+1] == k) {
        return lastOccurence(arr, mid+1, high, k);
    }
    
    // basic binary search
    if(arr[mid] < k) {
        return lastOccurence(arr, mid+1, high, k);
    } else {
        return lastOccurence(arr, low, mid-1, k);
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
        int k; cin >> k;
        
        int first = firstOccurence(arr, 0, n-1, k);
        
        if(first == -1) {
            cout << -1 << endl;
        } else {
            int last = lastOccurence(arr, 0, n-1, k);
            cout << first << " " << last << endl;
        }
    }
}