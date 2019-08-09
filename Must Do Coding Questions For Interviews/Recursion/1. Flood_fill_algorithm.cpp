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
    } 
    cout << endl;
}

void floodFillUtil(int **arr, int m, int n, int x, int y, int k, int orig_color) {

    // check for base conditions
    if(x<0 || x>=m || y<0 || y>=n) return;
    
    // if adjacent is of different color then return;
    if(arr[x][y] != orig_color) return;
    
    // make this location to new color
    arr[x][y] = k;
    

    // recur for all the adjacent places
    floodFillUtil(arr, m, n, x+1, y, k, orig_color);
    floodFillUtil(arr, m, n, x-1, y, k, orig_color);
    floodFillUtil(arr, m, n, x, y+1, k, orig_color);
    floodFillUtil(arr, m, n, x, y-1, k, orig_color);
}

void floodFill(int **arr, int m, int n, int x, int y, int k) {

    // check for invalid input
    if(x<0 || x>=m || y<0 || y>=n) return;
    
    // get the original color to be changed
    int orig_color = arr[x][y];
    
    // this utility function changes all the adjacent original_color matrix locations to new_val k
    floodFillUtil(arr, m, n, x, y, k, orig_color);
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
        
        int x, y, k;
        cin >> x >> y >> k;
        
        floodFill(arr, m, n, x, y, k);
        printMatrix(arr, m, n);
    }
}