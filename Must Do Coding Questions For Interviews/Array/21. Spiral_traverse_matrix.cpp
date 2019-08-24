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
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

void printSpirally(int **arr, int m, int n) {
    
    int i, k = 0, l = 0;
    
    /*
        k = starting row index
        m = ending row index;
        l = starting column index;
        n = ending column index;
    */
    
    // loop until start < end in row and column
    while(k<m && l<n) {
        
        /* print horizontal row (left to right) */
        for(i = l; i<n; i++) {
            cout << arr[k][i] << " ";
        }
        
        // increment starting row index
        k++;
        
        /* print vertical row (top to down) */
        for(i = k; i<m; i++) {
            cout << arr[i][n-1] << " ";
        }
        
        // decrement ending column index
        n--;
        
        // since k has changed, check for condition
        if(k < m) {
            /* print horizontal row (right to left) (in bottom) */
            for(i = n-1; i>=l; i--) {
                cout << arr[m-1][i] << " ";
            }
            
            // decrement ending row index
            m--;
        }
        
        if(l < n) {
            /* print vertical row (down to top) */
            for(i = m-1; i>=k; i--) {
                cout << arr[i][l] << " ";
            }
            
            // increment starting column index
            l++;
        }
    }
    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int **arr = new int*[m];
        loop(i,0,m) arr[i] = new int[n];
        
        loop(i,0,m) loop(j,0,n) cin >> arr[i][j];
        
        printSpirally(arr, m, n);
    }
}