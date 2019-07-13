#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
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

ll int binomialCoefficient(int n, int r) {
    if(n < r) return 0;
    if(n == r) return 1;
    if(r == 1 || r == n-1) return n;
    
    ll final = 1;
    
    if(r > n-r) {
        r = n-r;
    }
    
    loop(i, 0, r) {
        final *= (n-i)%md;
        final /= (i+1)%md;
    }
    
    return final % md;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        ll bin_coeff = binomialCoefficient(n,r);
        cout << bin_coeff << endl;
    }
}