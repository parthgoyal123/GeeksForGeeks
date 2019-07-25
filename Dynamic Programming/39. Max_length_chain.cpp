#include <bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout << maxChainLen(p,n) << endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/

bool compare(const struct val &p1, const struct val &p2) {
    return p1.first <= p2.first;
}

int maxChainLen(struct val p[],int n) {
    sort(p, p+n, compare);
    
    int dp[n];
    dp[0] = 1;
    
    for(int i = 1; i<n; i++) {
        dp[i] = 1;
        for(int j = 0; j<i; j++) {
            if(p[i].first > p[j].second) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    int maximum = 1;
    for(int i = 1; i<n; i++) {
        maximum = max(maximum, dp[i]);
    }
    
    return dp[n-1];
}