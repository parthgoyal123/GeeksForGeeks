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
        
        ll hash[26] = {0};
        
        loop(i, 0, s.size()){
            hash[s[i]-'a']++;
        }
        int index = 0;
        for(int i = 25; i>=0; i--){
            int m = hash[i];
            while(m--){
                s[index] = i+'a';
                index++;
            }
        }
        cout << s << endl;
    }
}