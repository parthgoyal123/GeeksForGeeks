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

bool compare(const int &a, const int &b) {
    return (abs(a) < abs(b));
}

int getSumClosestToZero(int *arr, int n) {
    
    // if only one element
    if(n == 1)  return arr[0]*2;
    
    // sort on basis of abs value
    sort(arr, arr+n, compare);
    
    int minimum = INT_MAX;
    for(int i = 1; i<n; i++) {
        
        // if abs value of sum is equal, give priority to positive sum
        if(abs(arr[i] + arr[i-1]) <= abs(minimum)) {
            minimum = arr[i] + arr[i-1];
        }
    }
    
    return minimum;
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
        
        cout << getSumClosestToZero(arr, n) << endl;
    }
}