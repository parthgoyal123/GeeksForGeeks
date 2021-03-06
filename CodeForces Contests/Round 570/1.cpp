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

int getfirst(string &a, string &b) {
    int n1 = a.size();
    int n2 = b.size();

    int store1, store2;
    loopr(i,n2-1,0){
        if(b[i] == '1') {
            store1 = n2-i;
            break;
        }
    }

    loopr(i,n1-1,0){
        if(a[i] == '1' && (n1-i) >= store1) {
            store2 = n1-i;
            break;
        }
    }

    return abs(store1-store2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << getfirst(a, b) << endl;
    }
}