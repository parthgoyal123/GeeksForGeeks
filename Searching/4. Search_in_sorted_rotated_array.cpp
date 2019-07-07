#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int search(int *arr, int low, int high, int key){
    if(low > high){
        return -1;
    }
    
    int mid = low + (high-low)/2;
    if(arr[mid] == key){
        return mid;
    }
    
    // if sorted in first half
    if(arr[low] <= arr[mid]){
        if(key >= arr[low] && key <= arr[mid]){
            return search(arr, low, mid-1, key);
        } else{
            return search(arr, mid+1, high, key);   
        }
    }
    
    if(key <= arr[mid] && key >= arr[high]){
        return search(arr, mid+1, high, key);
    } else{
        return search(arr, low, mid-1, key);
    }
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
        } int k; cin >> k;
        
        int out = search(arr, 0, n-1,k);
        
        cout << out << endl;
    }
}