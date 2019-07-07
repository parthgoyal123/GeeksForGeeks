#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int separateEvenOdd(ll int *arr, int n){
    int even_number_index = 0;
    int odd_number_index = n-1;
    int count_odd = 0;
    
    while(even_number_index < odd_number_index){
        while(even_number_index < n && arr[even_number_index] % 2 == 1){
            even_number_index++;
        }
        
        while(odd_number_index >= 0 && arr[odd_number_index] % 2 == 0){
            odd_number_index--;
        }
        
        if(even_number_index < odd_number_index){
            swap(arr[even_number_index], arr[odd_number_index]);
        }
    }
    
    int i = 0;
    for (i = 0; i<n; i++){
        if(arr[i]%2 == 0){
            break;
        }
    }
    return i;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        
        int pivot = separateEvenOdd(arr, n);
        sort(arr, arr+pivot, greater<int>());
        sort(arr+pivot, arr+n);
        printArray(arr, n);
    }
}