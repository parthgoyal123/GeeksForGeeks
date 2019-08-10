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

ll int getMax(int **arr, int n) {
    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    loop(i,1,n) {
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][1], dp[i-1][0]);

    }

    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

int main(){
    
	int n;
  	cin >> n;
  	int **arr = new int*[n];
    loop(i,0,n) arr[i] = new int[3];

    loop(i,0,n) loop(j,0,3) cin >> arr[i][j];

    cout << getMax(arr, n) << endl;
    
}