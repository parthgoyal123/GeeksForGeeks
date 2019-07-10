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

int searchMaximum(int *arr, int low, int high) {
    if(low == high) return arr[low+1];
    
    int mid = low + (high-low)/2;
    
    if(arr[low] < arr[mid] && arr[mid] > arr[high]) {
        return searchMaximum(arr, mid, high);
    } else {
        return searchMaximum(arr, low, mid);
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
        }
        
        int smallest = searchMaximum(arr, 0, n-1);
        cout << smallest << endl;
    }
}