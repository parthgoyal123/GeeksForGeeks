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

int findBiotonicIndex(int *arr, int low, int high) {
    
    if(low == high) return low;
    
    int mid = low + (high-low)/2;
    
    // check if mid is 0 and possible scenarios
    if(mid == 0 && arr[0] > arr[1]) return 0;
    if(mid == 0 && arr[1] > arr[0]) return 1;
    
    // check if this middle element is the biotonic point
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
    
    // if we are currently in the decreasing sequence subarray, search in left
    if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]) {
        return findBiotonicIndex(arr, low, mid-1);
    }
    
    // if we are currently in the increasing sequence subarray, search in right
    else if (arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) {
        return findBiotonicIndex(arr, mid+1, high);
    }
}


int searchInDecreasing(int *arr, int low, int high, int k) {
    
    // base condition
    if(low > high) return -1;
    
    int mid = low + (high-low)/2;
    
    if(arr[mid] == k) return mid;
    
    if(arr[mid] < k) return searchInDecreasing(arr, low, mid-1, k);
    else return searchInDecreasing(arr, mid+1, high, k);
}

int searchInIncreasing(int *arr, int low, int high, int k) {
    
    // base condition
    if(low > high) return -1;
    
    int mid = low + (high-low)/2;
    
    if(arr[mid] == k) return mid;
    
    if(arr[mid] > k) return searchInIncreasing(arr, low, mid-1, k);
    else return searchInIncreasing(arr, mid+1, high, k);
}

int findNumberInBiotonic(int *arr, int n, int k) {
    
    // first find the largest element, biotonic point
    int index = findBiotonicIndex(arr, 0, n-1);
    
    // cout << "index : " << index << endl;
    
    // check if the number to be found is less than the greatest or not
    if(arr[index] < k) return -1;
    
    // check if this the element to be found;
    if(arr[index] == k) return index;
    
    // search both in left and right subarrays
    int left_index = searchInIncreasing(arr, 0, index, k);
    
    // check if not found in left
    if(left_index != -1) return left_index;
    
    int right_index = searchInDecreasing(arr, index, n-1, k);
    
    // check if the element is present in right 
    if(right_index != -1) return right_index;
    
    // if not found in any subarray
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
        int k; cin >> k;
        
        cout << findNumberInBiotonic(arr, n, k) << endl;
    }
}