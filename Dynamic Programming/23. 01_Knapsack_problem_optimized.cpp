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
    int dp[w+1];
    
    memset(dp, 0, sizeof(dp));
    
    loop(i,0,n) {
        loopr(j,w,wt[i]) {
            dp[j] = max(dp[j], dp[j-wt[i]] + v[i]);
        }
    }
    return dp[w];
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