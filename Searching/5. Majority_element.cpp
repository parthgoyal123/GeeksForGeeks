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

int majorityElement(int *arr, int n){
    int maj_index = 0;
    int count = 1;
    
    loop(i, 1, n){
        if(arr[maj_index] == arr[i]){
            count++;
        } else{
            count--;
        }
        
        if(count == 0){
            maj_index = i; count = 1;
        }
    }
    
    int actual_count = 0;
    loop(i, 0, n){
        if(arr[maj_index] == arr[i]){
            actual_count++;
        }
    }
    
    if(actual_count > n/2){
        return arr[maj_index];
    } else {
        return -1;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i, 0, n){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }
}