#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define md (1e9+7)
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

int LCS(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    
    int dp[m+1][n+1];
    
    loop(i,0,m+1) {
        loop(j,0,n+1) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (t[i-1] == s[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int LPS(string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return LCS(s, t);
}

bool isKPalindrome(string &s, int k) {
    return ((s.size() - LPS(s)) <= k);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(isKPalindrome(s, k)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}