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

ll int countStringsFormedUtil(int dp[][2][3], int n, int bc = 1, int cc = 2) {
    if(bc < 0 || cc < 0) return 0;
    if(n == 0) return 1;
    if(bc == 0 && cc == 0) return 1;
    
    if(dp[n][bc][cc] != -1) return dp[n][bc][cc];
    
    int res = countStringsFormedUtil(dp, n-1, bc, cc);
    res += countStringsFormedUtil(dp, n-1, bc-1, cc);
    res += countStringsFormedUtil(dp, n-1, bc, cc-1);
    
    dp[n][bc][cc] = res;
    return res;
}

ll int countStringsFormed(int n) {
    int dp[n+1][2][3];
    
    memset(dp, -1, sizeof(dp));
    
    return countStringsFormedUtil(dp, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << countStringsFormed(n) << endl;
    }
}