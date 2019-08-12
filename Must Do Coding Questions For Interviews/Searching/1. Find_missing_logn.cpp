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

int getMissing(int *arr, int n) {
    int l = 0;
    int r = n-2;
    
    while(l <= r) {
        
        // get the middle element index
        int mid = l + (r-l)/2;
        
        // if this is first missing, i.e mid is not-matching but previous matches
        if(arr[mid] != mid+1 && arr[mid-1] == mid) return mid+1;
        
        // if this is not the first, check for left half
        if(arr[mid] != mid+1) r = mid-1;
        
        // if mid is at its correct position, check for right half
        else l = mid+1;
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int arr[n-1];
        loop(i,0,n-1) cin >> arr[i];
        
        cout << getMissing(arr, n) << endl;
    }
}