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
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        sort(arr, arr+n);

        int count = 0;
        loop(i, 0, n-2){
            int k = i+2;
            loop(j, i+1, n-1){
                while(k<n && arr[i] + arr[j] > arr[k]){
                    k++;
                }
                count += k-j-1;
            }
        }

        cout << count << endl;
    }
}