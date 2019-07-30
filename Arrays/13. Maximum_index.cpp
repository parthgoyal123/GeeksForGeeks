#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
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

int getMaximumIndex(ll int *arr, int n) {
    ll int Lmin[n], Rmax[n];
    
    Lmin[0] = arr[0];
    Rmax[n-1] = arr[n-1];
    
    loop(i,1,n) {
        Lmin[i] = min(Lmin[i-1], arr[i]);
        Rmax[n-i-1] = max(Rmax[n-i], arr[n-i-1]);
    }
    
    // printArray(Lmin, n);
    // printArray(Rmax, n);
    
    int i = 0;
    int j = 0;
    int maxDiff = -1;
    
    while(i<n && j<n) {
        if(Lmin[i] <= Rmax[j]) {
            maxDiff = max(maxDiff, j-i);
            j += 1;
        } else {
            i += 1;
        }
    }
    
    delete[] Lmin;
    delete[] Rmax;
    
    return maxDiff;
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
        
        cout << getMaximumIndex(arr, n) << endl;
    }
}