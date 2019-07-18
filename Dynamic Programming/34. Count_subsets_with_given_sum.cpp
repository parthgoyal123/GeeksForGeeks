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

void printSubsets(bool **dp, int i, int sum, int& count, int *arr) {
    if(i <=0 || sum < 0) return;
    
    if(i == 1 && sum != 0 && dp[i][sum]) {
        count++;
        return;
    }
    
    if(i == 1 && sum == 0) {
        count++;
        return;
    }
    
    if(dp[i-1][sum] == true) {
        printSubsets(dp, i-1, sum, count, arr);
    }
    
    if (sum >= arr[i-1] && dp[i-1][sum-arr[i-1]]) { 
        printSubsets(dp, i-1, sum-arr[i-1], count, arr); 
    }
}

int countPerfectSum(int *arr, int n, int sum) {
    if(sum < 0) return 0;
    
    bool **dp = new bool*[n+1];
    loop(i,0,n+1) dp[i] = new bool[sum+1];
    
    loop(i,0,n+1) dp[i][0] = 1;
    loop(j,1,sum+1) dp[0][j] = 0;
    
    loop(i,1,n+1) {
        loop(j,1,sum+1) {
            if(j < arr[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    if(dp[n][sum] == 0) return 0;
    
    int count = 0;
    printSubsets(dp, n, sum, count, arr);
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        int sum; cin >> sum;
        
        cout << countPerfectSum(arr, n, sum) << endl;
    }
}