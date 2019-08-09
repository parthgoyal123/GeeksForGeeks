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

ll int merge(int *arr, int *temp, int l, int mid, int r) {
    
    // initialize the var
    int i = l;
    int j = mid;
    int k = l;
    
    ll int inv_count = 0;
    
    while(i < mid && j <= r) {
        
        if (arr[i] <= arr[j]) {  
            temp[k++] = arr[i++];  
        } else {  
            temp[k++] = arr[j++];  
            
            inv_count = inv_count + (mid - i);
        }  
    }
    
    /* Copy the remaining elements of left subarray  
    (if there are any) to temp*/
    while (i < mid)  
        temp[k++] = arr[i++];  
  
    /* Copy the remaining elements of right subarray  
    (if there are any) to temp*/
    while (j <= r)  
        temp[k++] = arr[j++];  
  
    /*Copy back the merged elements to original array*/
    for (i = l; i <= r; i++)  
        arr[i] = temp[i];  
  
    return inv_count;
}

ll int inversionCountUtil(int *arr, int *temp, int l, int r) {
    
    // intialise the inversion count
    ll int inversion_count = 0;
    
    if(r > l) {
        
        // get mid
        int mid = l + (r-l)/2;
        
        // get inversioncount for left and right subarray
        inversion_count = (ll)inversionCountUtil(arr, temp, l, mid);
        inversion_count += (ll)inversionCountUtil(arr, temp, mid+1, r);
        
        // add the inversion count for merging the sorted
        inversion_count += (ll)merge(arr, temp, l, mid+1, r);
    }
    
    return inversion_count;
}

ll int inversionCount(int *arr, int n) {
    int temp[n];
    return inversionCountUtil(arr, temp, 0, n-1);
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
        
        cout << inversionCount(arr, n) << endl;
    }
}