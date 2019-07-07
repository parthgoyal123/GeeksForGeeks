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

void Heapify(int *arr, int i, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;

    if(l<n && arr[l] > arr[largest]){
        largest = l;
    }

    if(r<n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, largest, n);
    }
}

void buildHeap(int *arr, int n){
    for(int i = n/2-1; i>=0; i--){
        Heapify(arr, i, n);
    }
}

void HeapSort(int *arr, int n){
    buildHeap(arr, n);
    for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i);
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
        HeapSort(arr, n);
        printArray(arr,n);
    }
}
