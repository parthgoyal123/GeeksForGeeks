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

ll getOperations(int *p, ll n, int k, int m) {
    
    ll count = 0;
    int j = 0;

    while(j<m) {
        int window_start = k*
    }
}

int main(){
    ll n;
    int m, k;
    cin >> n >> m >> k;
    int p[m];
    loop(i,0,m) cin >> p[i];

    cout << getOperations(p, n, k, m+1) << endl;

}