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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int countCoinChange(int *a, int m, int n) {
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    loop(i,0,m+1) dp[i][0] = 1;
    loop(j,1,n+1) dp[0][j] = 0;

    loop(i,1,m+1) {
        loop(j,1,n+1) {
            if (a[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i][j - a[i-1]]; 
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    loop(i,0,m+1) {
        loop(j,0,n+1) {
            cout << dp[i][j] << " ";
        } cout << endl;
    }
    return dp[m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        int a[m];
        loop(i,0,m) cin >> a[i];
        int n; cin >> n;
        
        cout << countCoinChange(a, m, n) << endl;
    }
}