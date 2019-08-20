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

void getRepeatedElements(int *arr, int n) {
    
    // get all elements in the range 0 to n-1;
    for(int i = 0; i<n+2; i++) {
        arr[i] -= 1;
    }
    
    // traverse through all elements
    for(int i = 0; i<n+2; i++) {
        
        int index = arr[i] % n;
        
        // check if the number is greater than n or less
        if(arr[index] >= n) {
            
            // if the num is less than equal to 2*n, that means repeated once
            if(arr[index] < 2*n) {
                cout << (arr[i]%n + 1) << " ";
            }
        }   

        // add n to arr[index]
        arr[index] += n;
    }
    
    // restore array to original
    for(int i = 0; i<n+2; i++) {
        arr[i] = arr[i]%n + 1;
    }
    
    // cout << endl;
    // printArray(arr, n+2);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n+2];
        loop(i,0,n+2) cin >> arr[i];
        
        getRepeatedElements(arr, n);
        cout << endl;
    }
}