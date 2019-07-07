#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

bool isPowerofTwo(ll x){
    return x && (!(x & (x-1)));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n;
        cin >> n;
        if(isPowerofTwo(n)){
            cout << "YES";
        } else{
            cout << "NO";
        } cout << endl;
    }
}