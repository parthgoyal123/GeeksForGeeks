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


void insertInArray(int *arr, int i){
    int key = arr[i];

    int j = i-1;

    while(j>=0 && arr[j] > key){
        swap(arr[j], arr[j+1]);
        j--;
    }
}

void InsertionSort(int *arr, int n){
    loop(i,0,n){
        insertInArray(arr, i);
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
        InsertionSort(arr, n);
        printArray(arr,n);
    }
}