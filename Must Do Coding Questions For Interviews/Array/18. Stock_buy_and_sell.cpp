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

void stockBuyAndSell(int *arr, int n) {
    
    int i = 0;
    
    int buy, sell;

    int count = 0;
    
    while(i < n) {
        
        // get buying point
        while(i+1 < n && arr[i+1] <= arr[i]) i++;
        
        // if reached last
        if(i+1 == n) break;
        
        buy = i;
        
        i++;
        
        // get selling point
        while(i<n && arr[i] >= arr[i-1]) i++;
        
        sell = i-1;
        
        cout << "(" << buy << " " << sell << ") ";
        
        // get number of buy and sell
        count++;
    }
    
    if(count == 0) cout << "No Profit" << endl;
    else cout << endl;
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
        
        stockBuyAndSell(arr, n);
    }
}