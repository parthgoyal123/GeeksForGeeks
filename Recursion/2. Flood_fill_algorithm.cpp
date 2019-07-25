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

void printMatrix(int **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) cout << arr[i][j] << " ";
    } cout << endl;
}

void floodFill(int **arr, int n, int m, int x, int y, int prev_color, int new_color) {
    if(x >= n || y >= m || x < 0 || y < 0) return;
    
    if(arr[x][y] != prev_color) return;
    
    arr[x][y] = new_color;
    
    floodFill(arr, n, m, x+1, y, prev_color, new_color);
    floodFill(arr, n, m, x-1, y, prev_color, new_color);
    floodFill(arr, n, m, x, y+1, prev_color, new_color);
    floodFill(arr, n, m, x, y-1, prev_color, new_color);
}

void floodFillPrint(int **arr, int n, int m, int x, int y, int k) {
    if(x >= n || y >= m || x < 0 || y < 0) {
        printMatrix(arr, n, m);
        return;
    }
    
    int prev_color = arr[x][y];
    
    int new_color = k;
    
    floodFill(arr, n, m, x, y, prev_color, new_color);
    
    printMatrix(arr, n, m);
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
        
        int x, y, k;
        
        cin >> x >> y >> k;
        
        floodFillPrint(arr, n, m, x, y, k);
    }
}