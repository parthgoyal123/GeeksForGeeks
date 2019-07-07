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

void PrintStack(stack<int> &s){
    if(!s.empty()){
        int x = s.top();
        s.pop();
        PrintStack(s);
        
        cout << x << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        stack <int> s;
        queue<int> q;
        loop(i,0,n){
            cin >> arr[i];
        }
        
        loop(i,0,n){
            // int x = q.fnont();
            
            while(!s.empty() && arr[i] > s.top()){
                s.pop();
            }
            
            s.push(arr[i]);
        }
        
        PrintStack(s);
        cout << endl;
        
    }
}