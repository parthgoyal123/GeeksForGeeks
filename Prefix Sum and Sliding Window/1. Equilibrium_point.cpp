#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll int arr[n+1];
        arr[0] = 0;
        loop(i,1,n+1){
            int temp;
            cin >> temp;
            arr[i] = arr[i-1] + temp;
        }
        
        // int index = 0;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        // check for first
        int flag = 0;
        loop(i,1,n+1){
            if(arr[i-1] == (arr[n]-arr[i])){
                cout << i << endl; flag = 1;
                break;
            }
        }
        if(!flag){
            cout << -1 << endl;
        }
        
    }
}