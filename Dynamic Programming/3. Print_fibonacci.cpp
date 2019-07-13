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

void printFibTillN(int n) {
    if(n<0) return;
    if(n == 1) {
        cout << 1 << endl;
        return;
    } if(n == 2) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    
    ll int *fib = new ll int[n];
    fib[0] = 1; fib[1] = 1;
    
    cout << fib[0] << " " << fib[1] << " ";
    
    loop(i,2,n){
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        printFibTillN(n);
    }
}