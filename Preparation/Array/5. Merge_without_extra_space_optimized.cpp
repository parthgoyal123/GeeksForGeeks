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

int nextGap(int gap) {
    if(gap<=1) return 0;
    
    return ((gap/2) + (gap%2));
}

void merge(int *arr1, int n, int *arr2, int m) {
    
    // initialize the loop vars and gap
    int i, j, gap = n+m;
    
    // looping for various gaps
    for(gap = nextGap(gap); gap>0; gap = nextGap(gap)) {
        
        // comparing elements in the first array
        for(i = 0; i+gap < n; i++) {
            
            // swap elements
            if(arr1[i] > arr1[i+gap]) {
                swap(arr1[i], arr1[i+gap]);
            }
        }
        
        // comparing elements in both arrays
        
        // get initial value of j
        j = (gap > n)? gap-n: 0;
        
        for(; i<n && j<m; i++, j++) {
            
            // swap elements
            if(arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
        }
        
        // comparing elements in the second array
        if(j<m) {
            
            for(j = 0; j+gap < m; j++) {
                
                // swap elements
                if(arr2[j] > arr2[j+gap]) {
                    swap(arr2[j], arr2[j+gap]);
                }
            }
        }
    }
        
    printArray(arr1, n);
    printArray(arr2, m);
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