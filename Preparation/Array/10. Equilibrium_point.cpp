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

int getEquilibriumPoint(int* arr, int n) {
    
    // if only one element is present then it is equilibrium
    if(n == 1) return 1;
    
    // calculate the prefix sum
    ll int prefix_sum[n];
    prefix_sum[0] = arr[0];
    
    loop(i,1,n) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    
    // equilibrium point should satisfy the condition
    loop(i,1,n) {
        if(prefix_sum[i-1] == prefix_sum[n-1] - prefix_sum[i]) return (i+1);
    }
    
    // if no equilibrium point
    return -1;
    
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
        
        cout << getEquilibriumPoint(arr, n) << endl;
    }
}