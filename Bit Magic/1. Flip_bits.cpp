#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int ones = 0, zeros = 0;
        loop(i,0,n){
            cin >> arr[i];
            if(arr[i] == 1){
                ones++;
            } else{
                zeros++;
            }
            arr[i] = (arr[i] == 0)? 1:-1;
        }
        
        if(zeros == 0){
            cout << ones << endl;
            continue;
        }
        
        int curr = 0;
        int dp[n];
        int max1  = arr[0];
        dp[0] = arr[0];
        loop(i,1,n){
            dp[i] = max(dp[i-1]+arr[i], arr[i]);
            if(dp[i] > max1){
                max1 = dp[i];
            }
        }
        
        cout << max1 + ones << endl;
    }
}