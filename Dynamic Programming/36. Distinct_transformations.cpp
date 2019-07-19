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

ll int distinctTransformations(string &s, string &t) {
    int n1 = s.size();
    int n2 = t.size();
    
    ll int dp[n2+1][n1+1];
    memset(dp, 0, sizeof(dp));
    
    loop(j,0,n1+1) dp[0][j] = 1;
    loop(i,1,n2+1) dp[i][0] = 0;
    
    loop(i,1,n2+1) {
        loop(j,1,n1+1) {
            if(t[i-1] == s[j-1]) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
    }
    return dp[n2][n1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        
        cout << distinctTransformations(s, t) << endl;
    }
}