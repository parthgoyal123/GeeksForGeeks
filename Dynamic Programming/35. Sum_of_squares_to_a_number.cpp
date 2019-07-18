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

void countNumber(bool **dp, int i, int sum, int& count, vector<int> &arr) {
    if(i == 1 && sum == 0) {
        count++;
        return;
    }
    
    if(i == 1 && sum != 0 && dp[i][sum]) {
        count++;
        return;
    }
    
    if(dp[i-1][sum]) {
        countNumber(dp, i-1, sum, count, arr);
    }
    
    if(arr[i-1] <= sum && dp[i][sum - arr[i-1]]) {
        countNumber(dp, i-1, sum - arr[i-1], count, arr);
    }
}

int numberOfWays(int sum, int k) {
    if(sum == 1) return 1;
    vector<int> arr;
    
    int l = 1;
    while(pow(l,k) <= sum) {
        arr.pb(pow(l,k));
        l++;
    }
    
    int n = l-1;
    
    bool** dp = new bool* [n+1];
    loop(i,0,n+1) dp[i] = new bool[sum+1];
    
    loop(i,0,n+1) dp[i][0] = 1;
    loop(j,1,sum+1) dp[0][j] = 0;
    
    loop(i,1,n+1) {
        loop(j,1,sum+1) {
            if(j >= arr[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int count = 0;
    countNumber(dp, n, sum, count, arr);
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int sum, k;
        cin >> sum >> k;
        
        cout << numberOfWays(sum, k) << endl;
    }
}