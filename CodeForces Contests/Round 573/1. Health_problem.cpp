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
void printMatrix(T **arr, int m, int n){
    loop(i,0,m){
        loop(j,0,n) cout << arr[i][j] << " ";
    } cout << endl;
}

int main(){
    int n;
    cin >> n;

    if(n%4 == 0) {
        cout << 1 << " A" << endl;
    }

    else if(n%4 == 1) {
        cout << 0 << " A" << endl;
    }

    else if(n%4 == 2) {
        cout << 1 << " B" << endl;
    }

    else if(n%4 == 3) {
        cout << 2 << " A" << endl;
    }
}