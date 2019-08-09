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
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

ll maxSubarraySum(int *arr, int n) {
    
    // if only one element is present
    if(n == 1) return arr[0];
    
    // set the prev index sum's
    ll prev_sum = arr[0];
    ll max_sum = arr[0];
    ll curr_sum;
    
    loop(i,1,n) {
        
        // sum ending at ith index, is either the number itself or sum or prev and current
        curr_sum = max((ll)arr[i], (ll)arr[i] + (ll)prev_sum);
        prev_sum = curr_sum;
        
        if(curr_sum > max_sum) max_sum = curr_sum;
    }
    
    return max_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << maxSubarraySum(arr, n) << endl;
    }
}