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

int* getMinOperations(int n) {
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    loop(i,3,n+1) {
        if(i%2 != 0) {
            arr[i] = 1 + arr[(i-1)];
        } else {
            arr[i] = 1 + arr[i/2];
        }
    }
    return arr;
}

int main(){
    int t;
    cin >> t;
    int *arr = getMinOperations(10000);
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
}