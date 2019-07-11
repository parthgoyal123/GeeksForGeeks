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
        string s1, s2;
        cin >> s1 >> s2;
        
        int i1 = s1.size()-1;
        int i2 = s2.size()-1;
        int carry = 0;
        string s = "";
        
        while(i1>= 0 && i2>=0) {
            int sum = (s1[i1] - '0') + (s2[i2] - '0') + carry;
            char c =(sum%2 + '0');
            s = c + s;
            
            (sum >= 2)? carry = 1: carry = 0;
            i1--;
            i2--;
        }
        
        while(i1>= 0) {
            int sum = (s1[i1] - '0') + carry;
            char c =(sum%2 + '0');
            s = c + s;
            
            (sum >= 2)? carry = 1: carry = 0;
            i1--;
        }
        
        while(i2>=0) {
            int sum = (s2[i2] - '0') + carry;
            char c =(sum%2 + '0');
            s = c + s;
            
            (sum >= 2)? carry = 1: carry = 0;
            i2--;
        }
        
        if(carry == 1) s = '1' + s;
        cout << s << endl;
    }
}