#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b,c) for(int i=a; i<=b; i+=c)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n,1){
        cout << arr[i] << " ";
    } cout << endl;
}

ll getLargestPrimeFactor(ll int n) {
    int max_prime = INT_MIN;
    
    while(n%2 == 0) {
        n = n/2;
        max_prime = 2;
    }
    
    loop(i, 3, sqrt(n), 2) {
        while(n%i == 0) {
            max_prime = i;
            n=n/i;
        }
    }
    if(n>2) {
        if(n > max_prime) max_prime = n;
    }
    return max_prime;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n;
        cin >> n;
        
        ll greatest_prime_factor = getLargestPrimeFactor(n);
        cout << greatest_prime_factor << endl;
    }
}