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
    
    // Base cases 
    if (low > high) return -1; 
  
    if (low==high) return arr[low];
  
    // Find the middle point 
    int mid = (low + high) / 2; 
  
    // If mid is even and element next to mid is 
    // same as mid, then output element lies on 
    // right side, else on left side 
    if (mid%2 == 0) { 
        if (arr[mid] == arr[mid+1]) 
            return getElementOnlyOnce(arr, mid+2, high); 
        else
            return getElementOnlyOnce(arr, low, mid); 
    } 
    else { // If mid is odd  
        if (arr[mid] == arr[mid-1]) 
            return getElementOnlyOnce(arr, mid+1, high); 
        else
            return getElementOnlyOnce(arr, low, mid-1); 
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