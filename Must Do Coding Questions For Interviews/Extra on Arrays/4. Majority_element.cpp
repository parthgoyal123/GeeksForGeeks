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
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

int getMajorityElement(int *arr, int n) {
    
    // initialize the required vars
    int count = 1;
    int index = 0;
    
    for(int i = 1; i<n; i++) {
        if(arr[index] == arr[i]) count++;
        else count--;
        
        if(count == 0) {
            count = 1;
            index = i;
        }
    }
    
    // check if the index element if greater than N/2 times;
    int majority_element = arr[index];
    count = 0;
    
    loop(i,0,n) {
        if(arr[i] == majority_element) count++;
        
        if(count > n/2) return majority_element;
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << getMajorityElement(arr, n) << endl;
    }
}