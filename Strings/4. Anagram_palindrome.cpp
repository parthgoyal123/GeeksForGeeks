#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

bool isAnagramPalindrome(string s){
    ll hash[26] = {0};
    
    int length = s.size();
    
    loop(i,0, length){
        hash[s[i]-'a']++;
    }
    
    if(length%2 == 0){
        loop(i,0,26){
            if(hash[i]%2 != 0){
                return false;
            }
        }
        return true;
    } else{
        int val=0;
        loop(i,0,26){
            if(hash[i]%2 == 1){
                val++;
            }
        }
        if(val == 1){
            return true;
        } 
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(isAnagramPalindrome(s)){
            cout << "Yes";
        } else{
            cout << "No";
        }
        cout << endl;
    }
}