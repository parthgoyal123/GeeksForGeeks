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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

ll dotProduct(int *arr, int *brr, int n) {
    ll dp = 0;
    loop(i,0,n) {
        dp += arr[i]*brr[i];
    }
    return dp;
}

ll maximizedDotProduct(int *arr, int n, int *brr, int m) {
    if(m>=n) return dotProduct(arr, brr, n);
    
    ll int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    loop(i,1,m+1) {
        loop(j,i,n+1) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + ((long long)arr[j-1]*brr[i-1]));
        }
    }
    
    // loop(i,0,m+1) {
    //     loop(j,0,n+1) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // }
    
    return dp[m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int arr[n], brr[m];
        loop(i,0,n) cin >> arr[i];
        loop(i,0,m) cin >> brr[i];
        
        cout << maximizedDotProduct(arr, n, brr, m) << endl;
    }
}