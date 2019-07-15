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

bool searchInMatrix(int **arr, int n, int m, int key) {
    if(key > arr[n-1][m-1] || key < arr[0][0]) return false;
    
    loop(i,0,n) {
        if(key >= arr[i][0] && key <= arr[i][m-1]) {
            int p = lower_bound(arr[i], arr[i] + m, key) - arr[i];
            if(arr[i][p] == key) {
                // cout << arr[i][p] << " " << p << " " << i << " " << key << " ";
                return true;
            }
            else return false;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int **arr = new int*[n];
        loop(i,0,n) arr[i] = new int[m];
        
        loop(i,0,n) loop(j,0,m) cin >> arr[i][j];
        int key; cin >> key;
        
        if(searchInMatrix(arr, n, m, key)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}