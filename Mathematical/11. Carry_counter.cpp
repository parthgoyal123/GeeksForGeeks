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

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n, m;
        cin >> n >> m;
        int carry = 0;
        int carry_count = 0;
        
        while(n > 0 && m > 0) {
            int sum = n%10 + m%10 + carry;
            if(sum>=10) {
                // cout << m << " " << n << "  ";
                carry = 1;
                carry_count++;
            }
                
            if(sum < 10) carry = 0;
            
            n = n/10;
            m = m/10;
        }
        
        ll int rem = (n == 0)? m:n;
        while(rem > 0) {
            int sum = rem%10 + carry;
            if(sum>=10) {
                // cout << rem << "  ";
                carry = 1;
                carry_count++;
            }
                
            if(sum < 10) carry = 0;
            
            rem = rem/10;
        }
        
        cout << carry_count << endl;
    }
}