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
        int n,k;
        cin >> n >> k;
        int arr[n];
        unordered_map<int,int> hash;
        loop(i,0,n){
            cin >> arr[i];
            hash[arr[i]]++;
        }
        int total_double_count = 0;
        int count = 0;

        loop(i,0,n){
            total_double_count += hash[k-arr[i]];
            
            if(k-arr[i] == arr[i]){
                total_double_count --;
            }
        }
        cout << (int)total_double_count/2 << endl;
    }
}