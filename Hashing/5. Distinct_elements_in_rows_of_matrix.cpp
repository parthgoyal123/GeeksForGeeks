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
        int n;
        cin >> n;
        int arr[n][n];
        map<int, int> hash[n];
        loop(i,0,n){
            loop(j,0,n){
                cin >> arr[i][j];
                hash[i][arr[i][j]]++;
            }
        }
    }
}