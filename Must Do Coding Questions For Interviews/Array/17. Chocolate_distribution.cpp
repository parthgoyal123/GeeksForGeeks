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

int getMinDifference(ll int *arr, int n, int m) {
    
    if(m > n) return -1;
    
    // sort the array
    sort(arr, arr+n);
    
    // "m" is the size of sliding window
    ll int diff = arr[m-1] - arr[0];
    
    for(int i = 1; i+m <= n; i++) {
        diff = min(diff, (ll)arr[m+i-1] - arr[i]);
    }
    
    return diff;
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
        int m; cin >> m;
        
        cout << getMinDifference(arr, n, m) << endl;
    }
}