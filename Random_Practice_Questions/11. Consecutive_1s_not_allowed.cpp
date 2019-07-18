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

void getFibonacci(int* arr, int n = 100) {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    loop(i,3,n+1) {
        arr[i] = ((ll)arr[i-1]%md + (ll)arr[i-2]%md)%md;
    }
}

int main(){
    int t;
    cin >> t;
    int *arr = new int[101];
    getFibonacci(arr);
    while(t--){
        int n;
        cin >> n;
        
        cout << arr[n] << endl;
    }
}