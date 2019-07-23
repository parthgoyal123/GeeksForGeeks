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

ll matrixChainOrder(int *arr, int n) {
    ll int dp[n][n];
    
    loop(i,1,n) dp[i][i] = 0;
    
    // Length of Brackets
    loop(L,2,n) {
        
        // Possible starting indices
        loop(i,1,n-L+1) {
            
            // Ending index corresponding to starting
            int j = i+L-1;
            
            // Get the minimum value for
            dp[i][j] = INT_MAX;
            
            // Possible ways to get that length (break from between)
            loop(k, i, j) {
                ll int count = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] =  min(dp[i][j], count);
            }
        }
    }
    
    return dp[1][n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << matrixChainOrder(arr, n) << endl;
    }
}