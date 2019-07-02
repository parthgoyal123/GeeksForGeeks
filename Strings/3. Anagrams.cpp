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
        string s1, s2;
        cin >> s1 >> s2;

        ll int hash1[26] = {0};
        ll int hash2[26] = {0};

        if(s1.size() != s2.size()){
            cout << "NO" << endl;
        } else{
            int length = s1.size();
            loop(i, 0, length){
                hash1[s1[i]- 'a']++;
                hash2[s2[i]- 'a']++;
            }
            int flag = 0;
            loop(i,0,26){
                if(hash1[i] != hash2[i]){
                    cout << "NO" << endl;
                    flag = 1;
                }
            }
            if(!flag){
                cout << "YES" << endl;
            }

        }
    }
}