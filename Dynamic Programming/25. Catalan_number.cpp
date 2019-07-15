#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
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

cpp_int catalanNumberUtil(int n, int k) {
    if(k > n-k) k = n-k;
    
    cpp_int num = 1;
    loop(i,0,k) {
        num *= (n-i);
        num /= (i+1);
    }
    
    num /= (n/2 + 1);
    return num;
}

cpp_int catalanNumber(int n) {
    if(n == 0 || n == 1) return 1;
    
    return catalanNumberUtil(2*n, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        cout << catalanNumber(n) << endl;
    }
}