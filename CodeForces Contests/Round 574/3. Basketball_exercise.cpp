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
void printMatrix(T **arr, int m, int n){
    loop(i,0,m){
        loop(j,0,n) cout << arr[i][j] << " ";
    } cout << endl;
}

ll int getLargestHeight(ll int *a, ll int *b, int n) {
    ll int dp[2][n+1];

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = a[0];
    dp[1][1] = b[0];

    loop(i, 2, n+1) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + a[i-1];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + b[i-1];
    }

    return max(dp[0][n], dp[1][n]);
}

int main(){
    
    int n;
    cin >> n;
    ll int arr[n];
    ll int brr[n];
    loop(i,0,n) cin >> arr[i];
    loop(i,0,n) cin >> brr[i];

    cout << getLargestHeight(arr, brr, n) << endl;
    
}