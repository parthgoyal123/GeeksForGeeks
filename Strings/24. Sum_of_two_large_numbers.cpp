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
        string x, y;
        cin >> x >> y;
        
        string ans = "";
        
        if(y.size() > x.size()) {
            cout << x << endl;
        } else {
            int i = x.size()-1;
            int j = y.size()-1;
            int carry = 0;
            
            while(i>=0 && j>=0) {
                int sum = (x[i] - '0') + (y[j] - '0') + (carry);
                char c = (sum%10) + '0';
                ans = c + ans;
                (sum >= 10)? carry = 1: carry = 0;
                // cout << ans << " ";
                
                i--;
                j--;
            }
            
            while(i>=0) {
                int sum = (x[i] - '0') + (carry);
                char c = (sum%10) + '0';
                ans = c + ans;
                (sum >= 10)? carry = 1: carry = 0;
                // cout << ans << " ";
                
                i--;
            }
            
            while(j>=0) {
                int sum = (y[j] - '0') + (carry);
                char c = (sum%10) + '0';
                ans = c + ans;
                (sum >= 10)? carry = 1: carry = 0;
                // cout << ans << " ";
                j--;
            }
            if(carry == 1) ans = '1' + ans;
            
            if(ans.size() == x.size()) {
                cout << ans << endl;   
            } else {
                cout << x << endl;
            }
        }
    }
}