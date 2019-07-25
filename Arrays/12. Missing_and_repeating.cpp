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

void getMissingRepeating(int *arr, int n, int &x, int &y) {
    int xor1 = arr[0] ^ 1;
    
    loop(i,1,n) {
        xor1 = arr[i] ^ xor1 ^ (i+1);
    }
    
    int set_bit = xor1 & ~(xor1 - 1);
    
    loop(i,0,n) {
        if(set_bit & arr[i]) x = x ^ arr[i];
        else y = y ^ arr[i];
        
        if(set_bit & (i+1)) x = x ^ (i+1);
        else y = y ^ (i+1);
    }
    
    loop(i,0,n) {
        if(arr[i] == y) {
            swap(x, y);
            break;
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
        int x = 0;
        int y = 0;
        
        getMissingRepeating(arr, n, x, y);
        
        cout << x << " " << y << endl;
    }
}