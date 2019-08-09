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

void sortArray(int *arr, int n) {
    
    // 0001111.....?.... 2222
    // 1..low..mid........high...2
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high) {
        
        // switch on the mid of the array
        switch(arr[mid]) {
            case 0: {
                swap(arr[low++], arr[mid++]);
                break;
            } case 1: {
                mid++;
                break;
            } case 2: {
                swap(arr[mid], arr[high--]);
                break;
            }
        }
    }
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
        
        sortArray(arr, n);
        printArray(arr, n);
    }
}