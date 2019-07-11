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

bool compare(int x, int y) {
    return abs(x) <= abs(y);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        sort(arr, arr+n, compare);
        int min = INT_MAX;
        int min_l;
        int min_r;
        
        if(n==1) {
            cout << 2*arr[0] << endl;
            continue;
        }
        
        loop(i, 1, n) {
            if(abs(arr[i-1] + arr[i]) <= min) {
                min = abs(arr[i-1] + arr[i]);
                min_l = i-1;
                min_r = i;
            }
        }
        cout << arr[min_l] + arr[min_r] << endl;
    }
}