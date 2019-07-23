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

int main(){
    ios_base::sync_with_stdio(false);
    ll int n, k;
    cin >> n >> k;

    ll int c = 2* (n + k);

    ll r = (-3 + sqrt(9 + 4*c))/2;

    cout << (n-r) << endl;
}