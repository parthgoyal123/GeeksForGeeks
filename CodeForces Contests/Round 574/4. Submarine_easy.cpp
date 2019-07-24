#include <bits/stdc++.h>
 
using namespace std;
 
#define ll unsigned long long
#define md 998244353
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
 
ll int getNew(ll a, ll b) {
    int p = floor(log10(a) + 1);   
    int q = floor(log10(b) + 1);
 
    ll num = 0;
    int power = 0;
    loop(i,0,p) {
        num = num + (b%10) * pow(10, power);
        b = b/10;
        power++;
 
        num = num + (a%10) * pow(10, power);
        a = a/10;
        power++;
    }
 
    return num%md;
}
 
int main(){
    
    int n;
    cin >> n;
    ll int arr[n];
    loop(i,0,n) cin >> arr[i];
 
    ll sum = 0;
 
    loop(i, 0, n) {
        loop(j, 0, n) {
            ll newvar = getNew(arr[i], arr[j]);
            sum = (sum%md + newvar%md)%md;
            // cout << newvar << " ";
        }
    }
 
    cout << sum << endl;
    
}