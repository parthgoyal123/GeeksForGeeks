#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void permute(string s){
    sort(s.begin(), s.end());
    do{
        cout << s << " ";
    } while(next_permutation(s.begin(), s.end()));
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        permute(s);
        cout << endl;
    }
}