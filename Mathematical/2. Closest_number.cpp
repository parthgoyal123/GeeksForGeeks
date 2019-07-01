#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >>m;
        
        int k = n/m;
        int a1 = k*m;
        int a2;
        if(n*m > 0)
            a2 = m*(k+1);
        else{
            a2 = m*(k-1);
        }
        
        if(abs(a1-n) < abs(a2-n)){
            cout << a1 << endl;
        } else{
            cout << a2 << endl;
        }
        
    }
}