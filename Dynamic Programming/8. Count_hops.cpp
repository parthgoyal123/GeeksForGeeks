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

int* calculateCombinations(int *brr, int n, int different_coins) {
    int *arr = new int[n+1];

    memset(arr, 0, sizeof(arr));
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    loop(i,4,n+1){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr;
}

int main(){
    int t;
    cin >> t;
    int brr[] = {1,2,3};
    int *arr = calculateCombinations(brr, 50, 3);
    
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
}