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
        ll int n;
        cin >> n;
        int count = 0;
        int index = 0;
        int loop_index = 0;
        
        while(n != 0){
            if(n&1){
                count++;
                index = loop_index + 1;
            }
            n = n >> 1;
            loop_index++;
        }
        
        if(count == 1){
            cout << loop_index << endl; 
        } else{
            cout << -1 << endl;
        }
        
    }
}