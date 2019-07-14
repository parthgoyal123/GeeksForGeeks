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

int maxSumIncreasingSubsequence(int *arr, int n) {
    if(n == 1) return arr[0];
    
    int max_sum[n];
    max_sum[0] = arr[0];
    
    loop(i,1,n) {
        max_sum[i] = arr[i];
        loop(j,0,i) {
            if(arr[i] > arr[j]) {
                max_sum[i] = max(max_sum[i], arr[i] + max_sum[j]);
            }
        }
    }
    
    printArray(max_sum, n);
    
    return *max_element(max_sum, max_sum+n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        loop(i,0,n) cin >> a[i];
        
        cout << maxSumIncreasingSubsequence(a, n) << endl;
    }
}