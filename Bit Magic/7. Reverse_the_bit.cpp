#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i, a, b) for(int i =a ; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back
#define INT_SIZE 32

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
        
        int flag = 1;
        int count = 0;
        int answer;
        loopr(i, INT_SIZE-1, 0) {
            if(flag && (((n >> i) & 1) == 1)) {
                flag = 0;
                count++;
                // cout << i << " ";
            }
            
            else if(!flag) {
                count++;
            }
            
            if (count == k) {
                
                if (((n >> i) & 1) == 1) {
                    n -= pow(2, i);
                }
                
                cout << n << endl;
                break;
            }
        }
        
    }
}