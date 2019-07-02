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

        int length = s.size();

        int con = 0, vowel = 0, ques = 0;
        int flag = 1;
        loop(i,0,length){
            char c = s[i];
            if(c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e'){
                vowel++;
                con = 0;
            }

            else if(c == '?'){
                vowel++;
                con++;
            }
            else{
                vowel = 0;
                con++;
            }

            if(vowel >= 6 || con >= 4){
                cout << 0 << endl;
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
        }
    }
}