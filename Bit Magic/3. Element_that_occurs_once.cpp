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
        int temp;
        int xor_ans = 0;
        loop(i,0,n){
            cin >> temp;
            xor_ans = xor_ans ^ temp;
        }
        cout << xor_ans << endl;
    }
}