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

int calculateNthSum(int *arr, int *brr, int m, int n, int N) {
    set<int> sums;
    
    loop(i, 0, m) {
        loop(j, 0, n) {
            sums.insert(arr[i] + brr[j]);
        }
    }
    
    if(sums.size() < N) return -1;
    
    set<int> :: iterator it = sums.begin();
    loop(i, 1, N) {
        it++;
    }
    return *it;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int a[m];
        int b[n];
        loop(i,0,m){
            cin >> a[i];
        } loop(i, 0, n) {
            cin >> b[i];
        } int N; cin >> N;
        
        int nth_sum = calculateNthSum(a, b, m, n, N);
        cout << nth_sum << endl;
        
    }
}