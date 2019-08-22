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

void reverseInGroups(int *arr, int n, int k) {
    
    for(int i = 0; i<n; i+=k) {
        
        // if k elements are available in front
        if(i+k < n)
            reverse(arr + i, arr + (i + k));
        
        // if less than k elements are available in front
        else {
            reverse(arr + i, arr + n);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        reverseInGroups(arr, n, k);
        printArray(arr, n);
    }
}