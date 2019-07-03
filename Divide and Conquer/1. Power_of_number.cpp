#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

ll int reverse(ll int n){
    ll count = 0;
    while(n){
        count = 10*count + n%10;
        n /= 10;
    }
    return count;
}

ll int power(ll int n, ll int r){
    if(r == 1){
        return n%MAX;
    }
    if(r == 0){
        return 1;
    }
    
    if(r%2 == 0){
        n = (n*n)%MAX;
        return power(n, r/2);
    } else{
        return (power((n*n)%MAX, r/2)*n)%MAX;
    }   
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n;
        cin >> n;
        
        ll int r = reverse(n);
        cout << (ll)power(n,r) << endl;
    }
}