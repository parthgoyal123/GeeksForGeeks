#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void printArray(int arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

void printSequence(int n, int actual, bool flag){
    if(flag && n+5 == actual){
        cout << n << " " << actual << " ";
        return;
    }
    if(!flag && n>0){
        cout << n << " ";
        printSequence(n-5, actual, false);
    } else{
        cout << n << " ";
        printSequence(n+5, actual, true);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        printSequence(n, n, false);
        cout << endl;
    }
}