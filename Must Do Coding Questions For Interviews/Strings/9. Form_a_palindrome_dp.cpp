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

int minInsertions(string &str) {
    
    int n = str.size();
    
    // dp[i][j] = minInsertions for str[i..j];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    int gap, l, h;
    
    // for every gap from 1 or n-1
    for(gap = 1; gap<n; gap++) {
        
        // for all possible substrings with length = "gap"
        for(l = 0, h = gap; h < n; l++, h++) {
            
            // if first and last character are same
            if(str[l] == str[h]) dp[l][h] = dp[l+1][h-1];
            else {
                dp[l][h] = 1 + min(dp[l][h-1], dp[l+1][h]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << minInsertions(str) << endl;
    }
}