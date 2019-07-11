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

void MinHeapify(int *arr, int i, int n) {
    int l = 2*i+1;
    int r = 2*i+2;
    
    int smallest = i;
    if(l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }
    if(r<n && arr[r] < arr[smallest]) {
        smallest = r;
    }
    
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, smallest, n);
    }
}

void buildHeap(int *arr, int n) {
    for(int i = n/2-1; i>=0; i--) {
        MinHeapify(arr, i, n);
    }
}

int extractMin(int *arr, int n) {
    int min = arr[0];
    swap(arr[0], arr[n-1]);
    MinHeapify(arr, 0, n-1);
    return min;
}

int kthSmallestElement(int *arr, int n, int k) {
    buildHeap(arr, n);
    
    int kth;
    loop(i, 0, k) {
        kth = extractMin(arr, n-i);
    }
    return kth;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        int k; cin >> k;
        
        int kth_element = kthSmallestElement(arr, n, k);
        cout << kth_element << endl;
    }
}