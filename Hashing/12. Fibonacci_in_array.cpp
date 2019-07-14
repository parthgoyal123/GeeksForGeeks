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

void getFibonacciNumbers(unordered_set<int> &fib, int n) {
    fib.insert(0);
    fib.insert(1);
    fib.insert(2);
    
    int prev_prev = 1;
    int prev = 2;
    
    while(prev_prev + prev < n+1) {
        fib.insert(prev_prev + prev);
        int temp = prev_prev;
        prev_prev = prev;
        prev = temp + prev;
    }
}


int main(){
    int t;
    cin >> t;
    unordered_set<int> fib;
    getFibonacciNumbers(fib, 1000);
    while(t--){
        int n;
        cin >> n;
        int a[n];
        loop(i,0,n) cin >> a[i];
        
        loop(i,0,n){
            if(fib.find(a[i]) != fib.end()) cout << a[i] << " ";
        } cout << endl;
    }
}