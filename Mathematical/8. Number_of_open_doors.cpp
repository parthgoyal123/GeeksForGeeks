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

ll int getPerfectSquare(ll n){
    ll int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        ll temp = sqrt(i);
        if(floor(temp) == temp){
            cnt++;
        }
    }
    
    // cout << cnt << " ";
    return cnt;
}

void countOpenDoors(ll int n){
    ll count = getPerfectSquare(n);
    cout << count << endl;
}   

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n;
        cin >> n;
        countOpenDoors(n);
    }
}