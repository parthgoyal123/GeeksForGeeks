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

int longestCommonSubstring(string &s1, string &s2, int n1, int n2) {
    
    // make dp[i][j] denotes longestCommonSubstring in s1[0..i] and s2[0..j]
    int dp[n1+1][n2+1];
    
    // store the current max substr
    int maxi = 0;
    
    for(int i = 0; i<=n1; i++) {
        for(int j = 0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                
                // if last characters match
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                    
                    // update maximum
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n1, n2;
        cin >> n1 >> n2;
        string s1, s2;
        cin >> s1 >> s2;
        
        cout << longestCommonSubstring(s1, s2, n1, n2) << endl;
    }
}