#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

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
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int>> heap;
        
        int number;
        loop(i, 0, n){
            cin >> number;
            
            heap.push(number);
        }
        
        loop(i, 0, k){
            cout << heap.top() << " ";
            heap.pop();
        } cout << endl;
    }
}