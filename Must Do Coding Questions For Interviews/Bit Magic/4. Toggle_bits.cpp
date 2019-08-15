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

ll int getToggleBits(int n, int l, int r) {
    
    ll int new_n = n;
    
    for(int i = l-1; i<r; i++) {
        
        // if the bit is set, subtract that bit "actual value"
        if((n >> i)& 1 == 1) {
            new_n -= (ll int)pow(2, i);
        } else {
            
            // if the bit is not set, set it up
            new_n += (ll int)pow(2, i);
        }
    }
    return new_n;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        
        ll int new_n = getToggleBits(n, l, r);
        cout << new_n << endl;
    }
}