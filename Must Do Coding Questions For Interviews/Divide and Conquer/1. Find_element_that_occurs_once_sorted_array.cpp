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

int getElementOnlyOnce(ll int *arr, int low, int high) {
    
    // base condition
    if(low > high) return -1; // no element appears once
    
    int mid = low + (high-low)/2;
    
    if(low == high) return arr[mid];
    
    // check if the mid position is odd or even
    if(mid%2 == 0) {
        
        // check that the next element should be equal
        if(arr[mid] == arr[mid+1]) {
            return getElementOnlyOnce(arr, mid+1, high);
        }
        
        // if next is not same but previous is same, check for left subarray
        else if(arr[mid+1] != arr[mid] && arr[mid-1] == arr[mid]) {
            return getElementOnlyOnce(arr, low, mid-1);
        } else {
            return arr[mid];
        }
    } else {
        
        // if element at previous position is not equal to curr mid
        if(arr[mid-1] == arr[mid]) {
            return getElementOnlyOnce(arr, mid+1, high);
        } 
        
        // if previous is not same, but next is same
        else if(arr[mid-1] != arr[mid] && arr[mid] == arr[mid+1]){
            return getElementOnlyOnce(arr, low, mid-1);
        } else {
            return arr[mid];
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
        ll int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << getElementOnlyOnce(arr,0, n-1) << endl;
    }
}