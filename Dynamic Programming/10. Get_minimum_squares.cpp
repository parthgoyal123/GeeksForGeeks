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

bool isPerfectSquare(int n) {
    double sq_root = sqrt(n);
    
    return (floor(sq_root) == sq_root);
}

int* getMinSquaresSum(int n = 1e4) {
    int *arr = new int[n+1];
    // memset(arr, 0, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    
    loop(i,4,n+1){
        if(isPerfectSquare(i)) {
            // cout << i << endl;
            arr[i] = 1;
        } else {
            arr[i] = i;
            // if(i == 5) cout << arr[i] << endl;
            loop(j,1,(int)(sqrt(i)+1)) {
                arr[i] = min(arr[i], 1 + arr[i - j*j]);
                // if(i == 5) cout<< j << "  " << arr[i] << endl;
            }
        }
    }
    return arr;
}

int main(){
    int t;
    cin >> t;
    int *arr = getMinSquaresSum(10000);
    // printArray(arr, 10001);
    while(t--){
        int n;
        cin >> n;
        
        cout << arr[n] << endl;
    }
}