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

ll int getNumberPaths(int m, int n) {
    
    // if reached at first row or column, there is only one way
    if(m == 1 || n == 1) return 1;
    
    // no way for invalid input
    if(m <= 0 || n <= 0) return 0;
    
    // get at [m-1, n] and [m, n-1] and from their only one way
    return (ll) getNumberPaths(m-1, n) + (ll) getNumberPaths(m, n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        
        cout << getNumberPaths(m, n) << endl;
    }
}