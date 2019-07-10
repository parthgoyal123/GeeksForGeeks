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

int searchMinimum(int *arr, int low, int high) {
    if(low > high) return arr[0];
    
    if(arr[low] < arr[high]) return arr[low];
    
    if(low == high) return arr[low];
    
    int mid = low + (high-low)/2;
    
    if(mid < high && arr[mid+1] < arr[mid]) {
        return arr[mid+1];
    }
    
    if(mid > low && arr[mid] < arr[mid-1]) {
        return arr[mid];
    }
    
    if(arr[high] > arr[mid]) {
        return searchMinimum(arr, low, mid-1);
    } return searchMinimum(arr, mid+1, high);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        
        int smallest = searchMinimum(arr, 0, n-1);
        cout << smallest << endl;
    }
}