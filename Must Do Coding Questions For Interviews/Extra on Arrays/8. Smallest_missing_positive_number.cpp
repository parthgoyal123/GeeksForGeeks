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
void printArray(T *arr, int low, int high){
    loop(i,low,high+1){
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

int getPartition(int *arr, int low, int high) {
    // define pivot
    int pivot = 0;
    int i = -1;
    
    // quicksort partition technique
    for(int j = low; j<=high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    return (i+1);
}

int findSmallestMissingNumber(int *arr, int n) {
    // partition +ve and -ve numbers
    int partition = getPartition(arr, 0, n-1);
    
    /* check if the partition was correct or not */
    // printArray(arr, 0, n-1);
    // cout << partition << " " << arr[partition] << endl;
    
    // arr[partition] is the first element that is positive
    for(int i = partition; i<n; i++) {
        
        // using abs() because the element might have been changed by some other previously
        int index = abs(arr[i]) - 1 + partition;
        
        // cout << "index : " << index << endl;
        
        // the index arr[i]-1 element should be positive
        if(index < n && arr[index] > 0) {
            arr[index] = 0 - arr[index];
        }
    }
    
    // get the first index >= partition, that is positive
    for(int i = partition; i<n; i++) {
        if(arr[i] > 0) return i-partition+1;
    }
    
    // if all elements exist in line, absent is the next element
    return n+1;
    
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
        
        cout << findSmallestMissingNumber(arr, n) << endl;
    }
}