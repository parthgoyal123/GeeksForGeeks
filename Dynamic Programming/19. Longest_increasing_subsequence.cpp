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

int longestIncreasingSubsequence(int *arr, int n) {
    if(n == 1) return 1;
    
    if(n == 2 && arr[1] > arr[0]) return 2;
    if(n == 2 && arr[1] < arr[0]) return 1;
    
    int longest[n];
    longest[0] = 1;
    
    loop(i,1,n) {
        longest[i] = 1;
        loop(j,0,i) {
            if(arr[i] > arr[j]) {
                longest[i] = max(longest[i], 1 + longest[j]);
            }
        }
    }
    return *max_element(longest, longest+n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        loop(i,0,n) cin >> a[i];
        
        cout << longestIncreasingSubsequence(a, n) << endl;
    }
}