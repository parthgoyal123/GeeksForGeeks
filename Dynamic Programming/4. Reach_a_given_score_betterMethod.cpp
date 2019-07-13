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
    
    loop(i,0,different_coins){
        loop(j, brr[i], n+1) {
            arr[j] += arr[j - brr[i]];
        }
    }
    return arr;
}

int main(){
    int t;
    cin >> t;
    int brr[] = {3,5,10};
    int *arr = calculateCombinations(brr, 1000, 3);
    
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
}