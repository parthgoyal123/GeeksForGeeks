#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template<typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i]/n << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n){
            int temp;
            cin >> temp;
            arr[i] = temp-1;
        }

        loop(i,0,n){
            arr[arr[i]%n] += n;
        }

        printArray(arr, n);
    }
}