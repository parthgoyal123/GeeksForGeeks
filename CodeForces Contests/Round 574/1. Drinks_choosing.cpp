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
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int temp;
    int count = (n%2 == 0) ? n/2: n/2+1;    
    int hash[k+1] = {0};

    int given = 0;
    loop(i,0,n) {
        cin >> temp;
        hash[temp]++;

        if(count > 0 && hash[temp] == 2) {
            given += 2;
            hash[temp] = 0;
            count--;
        }
    }

    cout << (given+count) << endl;
}