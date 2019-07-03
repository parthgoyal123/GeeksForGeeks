#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }

        int p = lower_bound(arr, arr+n, k) - arr;

        if(p == 0){
            cout << -1 << endl;
        }
        else if(arr[p] == k){
            cout << p << endl;
        } else{
            cout << p-1 << endl;
        }
    }
}