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

ll int getMaxTrappedWater(int *arr, int n) {
    
    // calculate left and right max for every index
    int left[n], right[n];
    
    left[0] = arr[0], right[n-1] = arr[n-1];
    
    for(int i =1; i<n; i++) {
        left[i] = max(left[i-1], arr[i]);
        right[n-i-1] = max(right[n-i], arr[n-1-i]);
    }
    
    ll total_water_trap = 0;
    
    // now for every index we have left and right max
    for(int i = 0; i<n; i++) {
        int min_height = min(left[i], right[i]);
        
        total_water_trap += (min_height - arr[i]);
    }
    
    return total_water_trap;
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
        
        cout << getMaxTrappedWater(arr, n) << endl;
    }
}