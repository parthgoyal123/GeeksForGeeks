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
void printMatrix(T **arr, int m, int n){
    loop(i,0,m){
        loop(j,0,n) cout << arr[i][j] << " ";
    } cout << endl;
}

ll int getMinCost(int *arr, int n) {
	ll dp[n];
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);

    loop(i,2,n) {
        dp[i] = min((ll)dp[i-1] + (ll)abs(arr[i] - arr[i-1]), (ll)dp[i-2] + (ll)abs(arr[i] - arr[i-2]));
    }

    return dp[n-1];
}

int main(){
    
	int n;
  	cin >> n;
  	int arr[n];
  	loop(i,0,n) cin >> arr[i];
  
  	cout << getMinCost(arr, n) << endl;
    
}