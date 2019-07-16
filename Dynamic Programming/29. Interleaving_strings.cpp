#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;

}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
bool isInterleave(string a, string b, string c) {
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    
    if(n1 + n2 != n3) return false;
    
    bool dp[n1+1][n2+1];
    memset(dp, false, sizeof(dp));
    
    for(int i = 0; i<=n1; i++) {
        for(int j = 0; j<=n2; j++) {
            if(i == 0 && j == 0) dp[i][j] = true;
            else if (i == 0 && b[j-1] == c[i+j-1]) dp[i][j] = dp[i][j-1];
            else if (j == 0 && a[i-1] == c[i+j-1]) dp[i][j] = dp[i-1][j];
            else if (a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1]) dp[i][j] = dp[i-1][j];
            else if (a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]) dp[i][j] = dp[i][j-1];
            else if (a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]) dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}
