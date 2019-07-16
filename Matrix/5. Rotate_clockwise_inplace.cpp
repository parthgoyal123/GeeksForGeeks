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
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
    } cout << endl;
}

void transposeMatrix(int **arr, int rows, int cols) {
    loop(i,0,rows) {
        loop(j,i+1,cols) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void reverseRowsMatrix(int **arr, int rows, int cols) {
    loop(i,0,rows) {
        loop(j,0,cols/2) {
            swap(arr[i][j], arr[i][cols-j-1]);
        }
    }
}

void rotateAndPrintMatrix(int **arr, int rows, int cols) {
    transposeMatrix(arr, rows, cols);
    reverseRowsMatrix(arr, rows, cols);
    printMatrix(arr, rows, cols);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int **arr = new int*[n];
        loop(i,0,n) arr[i] = new int[n];
        loop(i,0,n) loop(j,0,n) cin >> arr[i][j];
        
        rotateAndPrintMatrix(arr, n, n);
    }
}