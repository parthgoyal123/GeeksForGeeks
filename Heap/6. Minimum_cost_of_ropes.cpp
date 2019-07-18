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

ll int minCostOfRopes(int *arr, int n) {
    if(n == 1) return 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);
    
    ll int sum = 0;
    while(pq.size() > 1) {
        int top1 = pq.top();
        pq.pop();
        
        int top2 = pq.top();
        pq.pop();
        
        sum  += top1+top2;
        pq.push(top1+top2);
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << minCostOfRopes(arr, n) << endl;
    }
}