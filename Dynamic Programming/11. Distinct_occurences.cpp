#include <bits/stdc++.h>
using namespace std;
 
int subsequenceCount(string S, string T);
//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int subsequenceCount(string s, string t) {
    
    int n = s.size();
    int m = t.size();
    
    if(m > n) return 0;
    if(m == n) return (s == t);
    
    int count[m+1][n+1];
    
    for(int i = 1; i<=m; i++) count[i][0] = 0;
    for(int i = 0; i<=n; i++) count[0][i] = 1;
    
    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if(t[i-1] == s[j-1]) {
                count[i][j] = count[i][j-1] + count[i-1][j-1];
            } else {
                count[i][j] = count[i][j-1];
            }
        }
    }
    return count[m][n];
    
}
 
