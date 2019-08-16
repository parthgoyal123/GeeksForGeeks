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

ll int getCountBinaryStrings(int n) {
    /*
    one[n] = zero[n-1];
    zero[n] = zero[n-1] + one[n-1];
    */
    
    ll int one[n], zero[n];
    one[0] = 1;
    zero[0] = 1;
    
    for(int i = 1; i<n; i++) {
        one[i] = zero[i-1]%md;
        zero[i] = (zero[i-1]%md + one[i-1]%md)%md;
    }
    
    return (one[n-1]%md + zero[n-1]%md)%md;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        cout << getCountBinaryStrings(n) << endl;
    }
}