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

void heapify(int *arr, int i, int n){
    int l = (2*i) + 1;
    int r = (2*i) + 2;

    int largest = i;

    if(l < n && arr[l] > arr[i]){
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void buildMaxHeap(int *arr, int n){
    // We can start the index by n-1 also, but (n/2-1) is the first index that has children

    for(int i = n/2-1; i>=0; i--){
        heapify(arr, i, n);
    }
}  

void HeapSort(int *arr, int n){
    buildMaxHeap(arr, n);
    for (int i = n-1; i>=0; i--){
        // get the max element and store in the last and heapify with one less element i.e reduce the size of the array
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
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