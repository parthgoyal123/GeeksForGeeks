#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    int count[20][20];
    loop(i, 0, 20){
        count[0][i] = 1;
    }
    
    loop(i, 0, 20){
        count[i][0] = 1;
    }
    
    loop(i, 1, 20){
        loop(j, 1, 20){
            count[i][j] = count[i-1][j] + count[i][j-1];
        }
    }
    
    while(t--){
        int m, n;
        cin >> m >> n;
        cout << count[m-1][n-1] << endl;
    }
}