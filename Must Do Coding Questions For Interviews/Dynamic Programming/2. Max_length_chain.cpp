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
		
		cout<<maxChainLen(p,n)<<endl;
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

bool compare(const val &v1, const val &v2) {
    if(v1.second == v2.second) {
        return v1.first < v2.first;
    }
    return v1.second < v2.second;
}

int maxChainLen(struct val p[],int n) {
    // check for number of pairs
    if(n == 1) return 1;
    
    // sort the pairs
    sort(p, p+n, compare);
    
    int count = 0;
    int ending_time = INT_MIN;
    
    for (int  i = 0; i<n; i++) {
        if(p[i].first > ending_time) {
            count++;
            ending_time = p[i].second;
        }
    }
    return count;
    
}