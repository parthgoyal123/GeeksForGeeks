#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void compare (string &curr, string &res){
    if(curr.length() > res.length()){
        res = curr;
        curr = "";
    } else if (curr.length() == res.length()) {
        if(curr[0] == '0'){
            curr = "";
            return;
        }
        loop(i,0,curr.length()){
            int a = curr[i] - 'a';
            int b = res[i] - 'a';

            if(a==b){
                continue;
            } 
            else if(a>b){
                res = curr;
                curr = "";
                return;
            } else {
                curr = "";
                return;
            }
        }
    }
    curr = "";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        ll int count = 0;
        string curr_sum = "";
        string result = "";
        loop(i,0,s.length()){
            if(i<s.length() && s[i]>= 48 && s[i] <=57){
                if(curr_sum == "" && s[i] == 48){
                    continue;
                } else{
                    curr_sum = curr_sum + s[i];
                }
            } else{
                compare(curr_sum, result);
            }
        }
        if(result.length() == 0){
            cout << 0 << endl;
        } else
            cout << result << endl;
    }
}