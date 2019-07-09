#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int arr[], int k, int n)
{
    unordered_map<int, int> hash;
    int count = 0;
    for(int i =0; i<k; i++) {
        if(hash.find(arr[i]) == hash.end()) {
            hash[arr[i]] = 1;
            count++;
        } else {
            hash[arr[i]]++;
        }
    }
    
    cout << count << " ";
    
    for(int i = k; i<n; i++) {
        if(hash[arr[i-k]] == 1){
            count--;
            hash.erase(arr[i-k]);
        } else {
            hash[arr[i-k]]--;
        }
        
        if(hash.find(arr[i]) == hash.end()) {
            count++;
            hash[arr[i]] = 1;
        } else {
            hash[arr[i]]++;
        }
        
        cout << count << " ";
    }
    // cout << endl;
}