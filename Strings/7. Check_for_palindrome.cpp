#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int main(){
    int t;
    cin >> t;
    string temp;
    getline(cin, temp);
    while(t--){
        string s;
        getline(cin, s);

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // cout << s << endl;
        ll hash[26] = {0};

        ll length = s.length();

        ll start = 0;
        ll end = length-1;
        int flag = 0;
        while(start<end){
            if(((s[start]-'a')>=0 && (s[start]-'a')<26) || (s[start]>=48 && s[start]<=57)){
                char c = s[start];
                start++;
                while(1){
                    if(((s[end]-'a')>=0 && (s[end]-'a')<26) || (s[end]>=48 && s[end]<=57)){
                        break;
                    }
                    end--;
                }
                if(((s[end]-'a')>=0 && (s[end]-'a')<26) || (s[end]>=48 && s[end]<=57)){
                    if(c != s[end]){
                        // cout << c << " " << s[end] << endl;
                        cout << "NO" << endl;
                        flag = 1;
                        break;
                    }
                    // cout << c << " " << s[end] << endl;
                    end--;
                }
            } else{
                start++;
            }
        }
        if (!flag){
            cout << "YES" << endl;
        }

        // if(length%2 == 0){
        //     lloop(i,0,length/2){
                
        //     }
        // }
    }
}