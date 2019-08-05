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
    }
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

void merge(int *arr, int n, int *brr, int m) {
    
    // iterate through second array from last
    for (int i = m-1; i>=0; i--) {
        
        // store the last element of the arr
        int last = arr[n-1];
        
        if(last < brr[i]) continue;
        
        // loop variable
        int j;
        
        // loop till we find the optimal position of the array
        for(j = n-2; j >= 0 && arr[j] > brr[i]; j--) {
            arr[j+1] = arr[j];
        }
        
        // check conditions if there was some change in the arrays
        if(j != m-2 || last > brr[i]) {
            arr[j+1] = brr[i];
            brr[i] = last;
        }
    }
    
    printArray(arr, n);
    printArray(brr, m);
    cout << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int arr[n], brr[m];
        loop(i,0,n) cin >> arr[i];
        loop(i,0,m) cin >> brr[i];
        
        merge(arr, n, brr, m);
    }
}