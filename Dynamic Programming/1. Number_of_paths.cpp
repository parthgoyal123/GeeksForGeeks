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

int ** calculatePaths(int n, int m) {
    int **arr = new int*[n];
    loop(i,0,n) arr[i] = new int[m];
    
    loop(i,0,n) arr[i][0] = 1;
    loop(i,0,m) arr[0][i] = 1;
    
    loop(i,1,n){
        loop(j,1,m){
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
        }
    }
    return arr;
}

int main(){
    int t;
    cin >> t;
    int **arr = calculatePaths(15,15);
    while(t--){
        int n, m;
        cin >> n >> m;
        int paths = arr[n-1][m-1];
        cout << paths << endl;
    }
}