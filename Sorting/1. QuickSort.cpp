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

int partition (int arr[], int low, int high){
   int pivot = arr[high];
   
   int i = low;
   
   // get the first element that is larger than pivot
   while(i < high && arr[i] <= pivot){
       i++;
   }
   
   int curr = i+1;
   
   while(curr < high){
       if(arr[curr] <= pivot){
           swap(arr[i], arr[curr]);
           i++;
       }
       curr++;
   }
   
   swap(arr[i], arr[high]);
   return i;
}

void QuickSort(int *arr, int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        QuickSort(arr, low, p-1);
        QuickSort(arr, p+1, high);
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

        QuickSort(arr, 0, n-1);
        printArray(arr,n);
    }
}