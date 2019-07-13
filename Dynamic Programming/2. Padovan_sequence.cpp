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

void calculatePadovan(ll int *padovan, int n) {
    padovan[0] = 1; padovan[1] = 1; padovan[2] = 1;
    
    loop(i,3,n){
        padovan[i] = (padovan[i-2]%md + padovan[i-3]%md)%md;
    }
}

int main(){
    int t;
    cin >> t;
    ll int padovan[101];
    calculatePadovan(padovan, 101);
    while(t--){
        int n;
        cin >> n;
        cout << padovan[n] << endl;
    }
}