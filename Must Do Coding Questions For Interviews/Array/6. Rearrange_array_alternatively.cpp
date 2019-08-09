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

void rearrangeArray(ll int *arr, int n) {
    int max_index = n-1;
    int min_index = 0;
    
    ll int max_element = arr[max_index] + 1;
    
    loop(i,0,n) {
        if(i&1 == 1) {
            arr[i] += (ll)arr[min_index++]%max_element * (ll)max_element;
        } else {
            arr[i] += (ll)arr[max_index--]%max_element * (ll)max_element;
        }
    }
    
    loop(i,0,n) {
        arr[i] = arr[i]/max_element;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        rearrangeArray(arr, n);
        printArray(arr, n);
    }
}