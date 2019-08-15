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

void getMissingAndRepeating(int *arr, int n, int &x, int &y){
    
    // initialize xor_sum
    int xor_sum = 0;
    
    loop(i,0,n) xor_sum = xor_sum ^ arr[i] ^ (i+1);
    
    // get the first set bit
    int set_bit = xor_sum & ~(xor_sum - 1);
    
    // x will hold the xor of elements whose bit is set at first_set and y otherwise
    x = 0, y = 0;
    
    loop(i,0,n) {
        if(arr[i] & set_bit) x = x^arr[i];
        else y = y^arr[i];
        
        if((i+1) & set_bit) x = x^(i+1);
        else y = y^(i+1);
    }
    
    // check for repeating or missing
    loop(i,0,n) {
        if(arr[i] == x) {
            swap(x, y);
            return;
        }
    }
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
        
        int missing;
        int repeating;
        
        getMissingAndRepeating(arr, n, missing, repeating);
        
        cout << repeating << " " << missing << endl;
        
        
    }
}