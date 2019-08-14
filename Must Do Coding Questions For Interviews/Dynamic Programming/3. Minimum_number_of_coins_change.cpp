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

int coins[] = {1,2,5,10,20,50,100,200,500,2000};

void getChange(int n) {
    
    // get num of coins available
    int m = sizeof(coins)/sizeof(coins[0]);
    
    // get max coin index
    int i = m-1;
    
    while(n != 0) {

        // get the largest coin smaller than n
        while(n && i && coins[i] > n) {
            i--;
        }
        
        n -= coins[i];
        cout << coins[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        getChange(n);
    }
}