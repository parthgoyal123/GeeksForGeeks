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

ll int numTriplets(int arr[], int n) {
    
    // sort the array to check easily
    sort(arr, arr+n);
    
    ll count = 0;
    
    // loop from the greatest element
    loopr(i,n-1,0) {
        int j = 0;
        int k = i-1;
        
        while(j < k) {
            if(arr[j] + arr[k]  == arr[i]) {
                count++;
                j++;
                k--;
            } else if (arr[j] + arr[k] < arr[i]) {
                j++;
            } else if (arr[j] + arr[k] > arr[i]) {
                k--;
            }
        }
    }
    
    // if none satisfied the condition
    if(count == 0) return -1;
    
    return count;
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
        
        cout << numTriplets(arr, n) << endl;
    }
}