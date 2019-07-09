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

bool checkPalindrome(ll int n) {
    int ch[20];
    int index = 0;
    while(n) {
        ch[index] = n%10;
        n = n/10;
        index++;
    }
    
    int i = 0;
    while(i < index) {
        if(ch[i] != ch[index-1]) return false;
        
        i++;
        index--;
    }
    return true;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n;
        cin >> n;
        if(checkPalindrome(n)) cout << 1 << endl;
        else cout << 0 << endl;
        
    }
}