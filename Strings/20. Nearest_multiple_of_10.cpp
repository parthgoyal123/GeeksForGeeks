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

void nearestMultipleof10(string &s) {
    if(s[s.size() - 1] >= '0' && s[s.size()-1] <= '5') {
        s[s.size()-1] = '0';
        cout << s << endl;
        return;
    }
    
    s[s.size()-1] = '0';
    
    loopr(i, s.size()-2, 0) {
        if(s[i] >= '0' && s[i] <= '8') {
            s[i] = s[i]+1;
            break;
        } else {
            s[i] = '0';
        }
    }
    if(s[0] == '0') {
        s = '1' + s;
    }
    cout << s << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        nearestMultipleof10(s);
    }
}