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

int countCoinChange(int *a, int m, int n) {
    int arr[n+1] = {0};
    arr[0] = 1;
    
    loop(i,0,m) {
        loop(j, a[i], n+1) {
            arr[j] += arr[j-a[i]];
        }
    }
    return arr[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        int a[m];
        loop(i,0,m) cin >> a[i];
        int n; cin >> n;
        
        cout << countCoinChange(a, m, n) << endl;
    }
}