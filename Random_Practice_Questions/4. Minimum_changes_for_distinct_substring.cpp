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
        string s;
        cin >> s;
        set<char> dist;
        loop(i, 0, s.size()){
            dist.insert(s[i]);
        }
        cout << s.size() - dist.size() << endl;
    }
}