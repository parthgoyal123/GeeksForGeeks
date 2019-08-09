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

int getElement(int *arr, int n) {
    
    // construct two arrays
    int leftMax[n], rightMin[n];
    
    // initialize
    leftMax[0] = arr[0];
    rightMin[n-1] = arr[n-1];
    
    // build the two arrays
    loop(i,1,n) {
        leftMax[i] = max(arr[i], leftMax[i-1]);
        rightMin[n-i-1] = min(arr[n-i-1], rightMin[n-i]);
    }
    
    // loop to see which element is max from left and min from right
    loop(i,1,n-1) {
        if(leftMax[i] == rightMin[i]) return arr[i];
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << getElement(arr, n) << endl;
    }
}