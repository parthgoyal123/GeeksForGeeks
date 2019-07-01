#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

bool isParanthesisBalanced(string s){
    stack<char> p;

    if(s.size()%2 == 1){
        return false;
    }

    loop(i,0,s.size()){
        if(s[i] == '(' || s[i] == '[' ||s[i] == '{'){
            p.push(s[i]);
            continue;
        }

        if(p.empty()){
            return false;
        }
        else{
            switch(s[i]){
                case ')': {
                    int x = p.top();
                    if(x == '[' || x == '{'){
                        return false;
                    } else{
                        p.pop();
                    }
                    break;
                }
                case ']': {
                    int x = p.top();
                    if(x == '(' || x == '{'){
                        return false;
                    } else{
                        p.pop();
                    }
                    break;
                }
                case '}': {
                    int x = p.top();
                    if(x == '[' || x == '('){
                        return false;
                    } else{
                        p.pop();
                    }
                    break;
                }
            }
        }
        
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(isParanthesisBalanced(s)){
            cout << "balanced" << endl;
        } else{
            cout << "not balanced" << endl;
        }
    }
}