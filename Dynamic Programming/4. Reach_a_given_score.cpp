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

template <typename T>
void printMatrix(T **arr, int r, int c){
    loop(i,0,r){
        loop(j,0,c){
            cout << arr[i][j] << " ";
        } cout << endl;
    }
}

void calculateCombinations(int **arr, int r, int c, int *brr) {
    loop(i,0,r) arr[i][0] = 1;
    loop(i,1,c) arr[0][i] = 0;
    
    loop(i,1,r) {
        loop(j,1,c) {
            arr[i][j] = arr[i-1][j];
            if(j - brr[i] >= 0) arr[i][j] += arr[i][j-brr[i]];
        }
    }
}

int main(){
    int t;
    cin >> t;
    int **arr = new int*[4];
    loop(i,0,4){
        arr[i] = new int[1001];
    }
    
    int brr[] = {0,3,5,10};
    calculateCombinations(arr, 4, 1001, brr);
    
    // printMatrix(arr, 4, 1001);
    
    while(t--){
        int n;
        cin >> n;
        cout << arr[3][n] << endl;
    }
}