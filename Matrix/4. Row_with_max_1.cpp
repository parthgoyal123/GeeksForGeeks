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

int max1sRow(int **arr, int mn, int n) {
    int m = INT_MIN;
    int index = 0;
    loop(i,0,mn){
        int count = 0;
        int lower = lower_bound(arr[i], arr[i]+n, 1) - arr[i];
        if(lower != n){
            // cout << "NO" << " " << i << "  ";
            count = n - (lower);
        }
        if(m < count){
            m = count;
            index = i;
        }
    }
    return index;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int **arr;
        arr = new int*[m];
        loop(i, 0, m) {
            arr[i] = new int[n];
        }
        
        loop(j, 0, m) {
            loop(i,0,n){
                cin >> arr[j][i];
            }
        }
        
        cout << max1sRow(arr, m, n) << endl;
    }
}