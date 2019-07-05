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

int selectMin(int *arr, int i, int n){
    int m = arr[i];
    int ind = i;
    loop(j, i, n){
        if(arr[j]< m){
            m = arr[j];
            ind = j;
        }
    }
    return ind;
}

void SelectionSort(int *arr, int n){
    for(int i = 0; i<n; i++){

        int j = selectMin(arr, i, n);
        swap(arr[i], arr[j]);
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
        SelectionSort(arr, n);
        printArray(arr,n);
    }
}