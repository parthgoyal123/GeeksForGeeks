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

void transformArray(int *arr, int n) {
    
    int index;
    int prev_valid = INT_MIN;
    loop(i,0,n) {
        if(arr[i] != 0 && prev_valid != arr[i]) {
            prev_valid = arr[i];
            index = i;
        }
        
        else if(arr[i] != 0 && prev_valid == arr[i]) {
            arr[index] = 2*arr[index];
            arr[i] = 0;
            prev_valid = arr[index];
        }
    }
    
    index = 0;
    loop(i,0,n){
        if(arr[i] != 0) {
            arr[index] = arr[i];
            index++;
        }
    }
    loop(i, index, n) {
        arr[i] = 0;
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
        
        transformArray(arr, n);
        printArray(arr, n);
    }
}