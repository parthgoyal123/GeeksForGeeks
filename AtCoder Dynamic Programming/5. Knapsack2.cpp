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

ll int getMaxValue(int *w, int *v, int n, int W) {
    ll int dp[W+1];
    
    memset(dp, 0, sizeof(dp));
    
    loop(i,0,W+1) {
        loop(j,0,n) {
            if(w[j] <= i)
                dp[i] = max(dp[i], (ll)dp[i-w[j]] + (ll)v[j]);
        }
    }
    
    return dp[W];
}

int main(){
    int n, W;
    cin >> n >> W;
    int w[n], v[n];
    loop(i,0,n) cin >> w[i] >> v[i];

    cout << getMaxValue(w, v, n, W) << endl;
}