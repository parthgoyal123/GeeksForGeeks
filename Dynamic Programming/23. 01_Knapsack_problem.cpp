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

int getMaximumValueForKnapsack(int *wt, int *v, int n, int w) {
    int dp[n+1][w+1];
    memset(dp, -1, sizeof(dp));
    
    loop(i,0,n+1) {
        loop(j,0,w+1) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if(j - wt[i-1] >= 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i-1]] + v[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    // loop(i,0,n+1) {
    //     loop(j,0,w+1) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // }
    
    return dp[n][w];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n;
        cin >> w;
        int v[n], wt[n];
        loop(i,0,n) cin >> v[i];
        loop(i,0,n) cin >> wt[i];
        
        cout << getMaximumValueForKnapsack(wt, v, n, w) << endl;
    }
}