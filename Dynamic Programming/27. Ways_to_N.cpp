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

ll totalWaysToN(int *arr, int m, int n) {
    int dp[n+1] = {0};
    dp[0] = 1;
    
    loop(i,1,n+1) {
        dp[i] = 0;
        loop(j,0,m) {
            if (arr[j] <= i) {
                dp[i] = (dp[i]%md + dp[i - arr[j]]%md)%md;
            }
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m ,n;
        cin >> m >> n;
        int arr[m];
        loop(i,0,m) cin >> arr[i];
        
        cout << totalWaysToN(arr, m, n) << endl;
    }
}