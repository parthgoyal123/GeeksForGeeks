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

void merge(int *arr, int low, int mid, int high){
    
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1];
    int R[n2];

    for(int i = 0; i<n1; i++){
        L[i] = arr[low+i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = arr[mid+1+i];
    }

    int i = 0, j= 0, k = low;

    while(i<n1 && j<n2){
        if(L[i] > R[j]){
            arr[k] = R[j];
            k++;
            j++;
        } else if(L[i] < R[j]){
            arr[k] = L[i];
            k++;i++;
        } else{
            arr[k] = arr[k+1] = L[i];
            k += 2; i++;
            j++;
        }
    }

    while(i<n1){
        arr[k] = L[i];
        i++;k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;k++;
    }
}

void MergeSort(int *arr, int low, int high) {
    if(low<high){
        int mid = low + (high-low)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
        MergeSort(arr, 0, n-1);
        printArray(arr,n);
    }
}