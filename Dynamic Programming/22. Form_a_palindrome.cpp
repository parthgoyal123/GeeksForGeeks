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

bool isPalindrome(string &s) {
    int n = s.size();
    loop(i,0,n/2) {
        if(s[i] != s[n-i]) return false;
    }
    return true;
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
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    return dp[m][n];   
}

int formAPalindrome(string &s) {
    if(isPalindrome(s)) return 1;
    
    string t = s;
    reverse(t.begin(), t.end());
    int lcs = LCS(s, t);
    
    return s.size() - lcs;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        cout << formAPalindrome(s) << endl;
    }
}