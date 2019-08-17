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
#define N 16

int max_num = (int)pow(2,N) - 1;

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

ll int leftRotation(int n, int d) {
    
    // get the leftmost d digits in binary representation of n and get them to starting position
    ll int leftmost = n >> (N-d);
    
    // right shift the digits other than above
    ll int shifted = n << d;
    
    return (leftmost | (shifted & max_num));
}

ll int rightRotation(int n, int d) {
    
    // get the rightmost d digits in binary representation of n and get them to starting position
    ll int rightmost = n << (N-d);
    
    // right shift the digits other than above
    ll int shifted = n >> d;
    
    return ((rightmost & max_num) | shifted);
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        
        ll int num_after_left_rotation = leftRotation(n, d%N);
        ll int num_after_right_rotation = rightRotation(n, d%N);
        
        cout << num_after_left_rotation << endl;
        cout << num_after_right_rotation << endl;
    }
}