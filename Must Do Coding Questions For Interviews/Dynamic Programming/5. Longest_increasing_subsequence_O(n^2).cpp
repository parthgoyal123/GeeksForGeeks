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

int longestIncreasingSubsequence(int *arr, int n) {
    
    // dp[i] stores length of longest increasing subsequence ending at index i
    int dp[n];
    
    int max_length = 1;
    
    for(int i = 0; i<n; i++) {
        
        // number itself is increasing
        dp[i] = 1;
        
        // check if we can extend any of the previous sequences
        for(int j = 0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        
        max_length = max(max_length, dp[i]);
    }
    
    return max_length;
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
        
        cout << longestIncreasingSubsequence(arr, n) << endl;
    }
}