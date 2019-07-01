#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void permute(char *m, int start, int end){
    if(start+1 == end){
        // only one character
        cout << m << " ";
        return;
    }

    loop(i,start,end){
        swap(m[start], m[i]);
        permute(m, start+1, end);
        swap(m[start], m[i]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        char m[s.length()];
        loop(i, 0, s.length()){
            m[i] = s[i];
        }

        // loop(i, 0, s.length()){
        //     swap(m[0], m[i]);
        //     permute(m, 1, s.length()-1);
        //     swap(m[0], m[i]);
        // }
        // cout << endl;

        permute(m, 0, s.length());
        cout << endl;
    }
}